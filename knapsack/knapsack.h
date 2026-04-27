#pragma once

#include <vector>

namespace knapsack {

struct Item {
    int weight;
    int value;
};

auto maximum_value(int max_weight, std::vector<Item> const& items)
    -> std::vector<Item>;

} // namespace knapsack
