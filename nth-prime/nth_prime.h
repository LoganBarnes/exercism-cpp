#pragma once

#include <cmath>
#include <limits>
#include <stdexcept>

namespace nth_prime {

template <typename T>
auto is_prime(T x) -> bool {
    auto const max
        = static_cast<T>(std::floor(std::sqrt(static_cast<double>(x))));

    for (auto i = T(2); i <= max; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return x > 1;
}

template <typename T>
auto nth(T n) -> T {
    if (n < 1) {
        throw std::domain_error("n must be greater than 0");
    }

    auto prime = 1;
    for (auto i = T(2); n > T(0) && i < std::numeric_limits<T>::max(); ++i) {
        if (is_prime(i)) {
            --n;
            prime = i;
        }
    }
    return prime;
}

} // namespace nth_prime
