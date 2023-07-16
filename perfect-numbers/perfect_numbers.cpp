#include "perfect_numbers.h"

#include <algorithm>
#include <cmath>

namespace perfect_numbers {
namespace {

auto aliquot_sum(int n) {
    if (n <= 0) {
        throw std::domain_error{"n must be positive"};
    }

    auto       sum    = std::min(n - 1, 1);
    auto const sqrt_n = std::sqrt(n);

    auto i = 2;
    for (; i < sqrt_n; ++i) {
        // Since we already perform the % operation,
        // we might as well perform the / operation
        // for free (most machines can do both at once).
        if (n % i == 0) {
            sum += (n / i) + i;
        }
    }

    // Add the final factor if n is a perfect square.
    sum += (i == sqrt_n) * i;

    return sum;
}

} // namespace

auto classify(int n) -> classification {
    auto const sum  = aliquot_sum(n);
    auto const sign = (sum > n) - (sum < n); // -1, 0, or +1
    return static_cast<classification>(sign);
}

} // namespace perfect_numbers
