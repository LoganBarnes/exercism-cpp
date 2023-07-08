#include "armstrong_numbers.h"

#include <cmath>
#include <numeric>
#include <string>

namespace armstrong_numbers {

auto is_armstrong_number(int n) -> bool {
    auto const str = std::to_string(n);
    auto const len = static_cast<int>(str.length());

    return std::transform_reduce(
               str.begin(),
               str.end(),
               0,
               std::plus<>{},
               [&](auto c) { return static_cast<int>(std::pow(c - '0', len)); }
           )
        == n;
}

} // namespace armstrong_numbers
