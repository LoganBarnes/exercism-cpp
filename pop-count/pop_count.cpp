#include "pop_count.h"

namespace chicken_coop {

auto positions_to_quantity(unsigned long long positions) -> unsigned {
    auto quantity = 0u;
    while (positions) {
        positions &= positions - 1ULL;
        ++quantity;
    }
    return quantity;
}

} // namespace chicken_coop
