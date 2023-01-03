#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

auto steps(int n) -> uint64_t {

    for (auto i = 0ULL; n > 0; ++i) {
        if (n == 1) {
            return i;
        }
        if (n % 2 == 0) {
            n  >>= 1;
        } else {
            n = n * 3 + 1;
        }
    }

    throw std::domain_error("");
}

} // namespace collatz_conjecture
