#pragma once

#include <algorithm>
#include <cctype>
#include <numeric>
#include <string>

namespace luhn {

inline auto valid(std::string s) { // Attempting as few (ish) lines as possible.
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

    if (s.size() < 2 || !std::all_of(s.begin(), s.end(), isdigit)) { return false; }

    auto const process = [end = s.data() + s.size() - 1u](char const& c) {
        auto const digit = static_cast<size_t>(c - '0');
        return digit + (digit - (digit > 4) * 9u) * (static_cast<unsigned>(end - &c) % 2u);
    };
    return std::transform_reduce(s.rbegin(), s.rend(), 0, std::plus<>{}, process) % 10 == 0;
}

} // namespace luhn
