#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

auto steps(int n) -> uint64_t {
    for (auto i = 0ULL; n > 0; ++i, n = (n % 2 == 0) ? n >> 1 : n * 3 + 1) {
        if (n == 1) { return i; }
    }

    throw std::domain_error("Non-positive input");
}

} // namespace collatz_conjecture
