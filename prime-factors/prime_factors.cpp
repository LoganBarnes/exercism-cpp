#include "prime_factors.h"

namespace prime_factors {

// Discovered a more optimal solution from voxEko. Thanks!
auto of(int number) -> std::vector<int> {
    auto factors = std::vector<int>{};

    auto check_and_append = [&factors, &number](int divisor) {
        for (; number % divisor == 0; number /= divisor) {
            factors.emplace_back(divisor);
        }
    };

    // Check the only even prime.
    check_and_append(2);

    // Check all odd primes up to sqrt(number):
    for (int i = 3; i * i <= number; i += 2) {
        check_and_append(i);
    }

    // Include the remaining prime factor.
    if (number > 2) {
        factors.emplace_back(number);
    }

    return factors;
}

} // namespace prime_factors
