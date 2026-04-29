#pragma once

#include <vector>

namespace knapsack {

struct Item {
    int weight = 0;
    int value  = 0;
};

inline auto operator<(Item const& lhs, Item const& rhs) -> bool {
    return lhs.value < rhs.value;
}

auto maximum_value(int max_weight, std::vector<Item> const& items) -> int;

} // namespace knapsack
