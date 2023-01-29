#pragma once

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace nth_prime {

template <typename T>
auto is_prime(T x) -> bool {
    auto const largest_divisor = std::floor(std::sqrt(static_cast<double>(x)));
    auto const end             = static_cast<T>(largest_divisor) + T(1);

    for (auto i = T(2); i < end; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return x > 1;
}

template <typename T>
auto nth(T n) -> T {
    static_assert(std::is_integral_v<T>);

    if (n < 1) {
        throw std::domain_error("n must be greater than 0");
    }

    constexpr auto max_i = std::numeric_limits<T>::max();

    auto prime = 1;
    for (auto i = T(2); n > T(0) && i <= max_i; ++i) {
        if (is_prime(i)) {
            --n;
            prime = i;
        }
    }
    return prime;
}

} // namespace nth_prime
