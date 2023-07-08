#include "luhn.h"

#include <algorithm>
#include <cctype>
#include <numeric>

namespace luhn {

// Doing things the 'std' way for fun
auto valid(std::string s) -> bool {
    auto const is_space  = [](char c) { return std::isspace(c); };
    auto const not_digit = [](char c) { return !std::isdigit(c); };

    // Remove whitespace.
    s.erase(std::remove_if(s.begin(), s.end(), is_space), s.end());

    // Check for invalid length or non-digit characters.
    if (s.size() < 2 || std::any_of(s.begin(), s.end(), not_digit)) { return false; }

    // Convert and sum the digits.
    auto const process = [i = 0u](char c) mutable {
        auto const digit = static_cast<size_t>(c - '0');
        return digit + (digit - (digit > 4) * 9u) * (i++ % 2); // Attempt at a one-liner.
    };
    return std::transform_reduce(s.rbegin(), s.rend(), 0, std::plus<>{}, process) % 10 == 0;
}

} // namespace luhn
