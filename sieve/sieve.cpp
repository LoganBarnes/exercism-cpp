#include "sieve.h"

#include <unordered_set>

namespace sieve {

auto primes(int limit) -> std::vector<int> {
    auto non_primes = std::unordered_set<int>{};
    auto primes     = std::vector<int>{};

    for (auto i = 2; i <= limit; ++i) {
        if (non_primes.find(i) == non_primes.end()) {
            primes.emplace_back(i);

            for (auto j = i * 2; j <= limit; j += i) {
                non_primes.emplace(j);
            }
        }
    }

    return primes;
}

} // namespace sieve
