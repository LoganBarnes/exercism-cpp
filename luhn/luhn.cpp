#include "luhn.h"

#include <algorithm>
#include <cctype>
#include <numeric>

namespace luhn {

struct counting_iter {
    size_t count;
    auto operator++() { ++count; }
    auto operator*() -> size_t& { return count; }
};

// Doing things the 'std' way for fun
auto valid(std::string s) -> bool {
    auto const is_space  = [](char c) { return std::isspace(c); };
    auto const not_digit = [](char c) { return !std::isdigit(c); };

    // Remove spaces
    s.erase(std::remove_if(s.begin(), s.end(), is_space), s.end());

    // Check for invalid length or non-digits
    if (s.size() < 2)                               { return false; }
    if (std::any_of(s.begin(), s.end(), not_digit)) { return false; }

    auto const process_digit = [](char c, size_t i) {
        auto const digit = static_cast<size_t>(c - '0');
        // An attempt to remove any 'if' statements.
        return digit + (digit - (digit > 4) * 9u) * (i % 2);
    };

    // Convert and sum all digits
    auto const sum = std::transform_reduce(
        s.rbegin(), s.rend(), counting_iter{0}, 0, std::plus<>{}, process_digit
    );
    return sum % 10 == 0;
}

} // namespace luhn
