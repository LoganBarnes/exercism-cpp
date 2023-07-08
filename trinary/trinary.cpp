#include "trinary.h"

namespace trinary {

auto to_decimal(std::string const& s) -> int {
    auto result = 0;
    auto base   = 1;

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        char c = *it;

        if (c < '0' || '2' < c) { return 0; }

        result += (c - '0') * base;
        base *= 3;
    }
    return result;
}

} // namespace trinary
