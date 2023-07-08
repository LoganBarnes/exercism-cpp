#pragma once

#include <algorithm>
#include <cctype>
#include <numeric>
#include <string>

namespace luhn {

inline auto valid(std::string s) { // Attempting as few lines as possible.
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

    if (s.size() < 2 || !std::all_of(s.begin(), s.end(), isdigit)) { return false; }

    auto const process = [i = 0u](char c) mutable {
        auto const digit = static_cast<size_t>(c - '0');
        return digit + (digit - (digit > 4) * 9u) * (i++ % 2);
    };
    // This is broken on exercism servers
    // return std::transform_reduce(s.rbegin(), s.rend(), 0, std::plus<>{}, process) % 10 == 0;

    auto digits = std::vector<unsigned>(s.size());
    std::transform(s.rbegin(), s.rend(), digits.begin(), process);
    return std::accumulate(digits.begin(), digits.end(), 0u) % 10 == 0;
}

} // namespace luhn
