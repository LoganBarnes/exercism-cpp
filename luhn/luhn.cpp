#include "luhn.h"

#include <algorithm>
#include <cctype>
#include <numeric>

namespace luhn {

// Doing things the 'std' way for fun
auto valid(std::string s) -> bool {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return std::isspace(c); }), s.end());

    if (s.size() < 2) { return false; }
    if (std::any_of(s.begin(), s.end(), [](char c) { return !std::isdigit(c); })) { return false; }

    return std::transform_reduce(s.rbegin(), s.rend(), 0, std::plus<>{}, [i = 0u](char c) mutable {
        auto const digit = static_cast<size_t>(c - '0');
        return digit + (digit - (digit > 4) * 9u) * (i++ % 2);
    }) % 10 == 0;
}

} // namespace luhn
