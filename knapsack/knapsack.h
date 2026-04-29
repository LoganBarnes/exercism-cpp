#pragma once

#include <vector>

namespace knapsack {

struct Item {
    int weight = 0;
    int value  = 0;
};

auto maximum_value(int max_weight, std::vector<Item> const& items) -> int;

} // namespace knapsack
