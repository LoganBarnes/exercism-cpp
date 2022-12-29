#include "grains.h"

#include <limits>
#include <stdexcept>
#include <string>

namespace grains {

auto square(uint32_t s) -> uint64_t {
    if (1 > s || s > 64) {
        throw std::domain_error(std::to_string(s) + " not in range [1, 64]");
    }
    return 1ULL << (s - 1U);
}

auto total() -> uint64_t {
    return std::numeric_limits<uint64_t>::max();
}

} // namespace grains
