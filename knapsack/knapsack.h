#pragma once

#include <algorithm>
#include <vector>

namespace knapsack {

struct Item { int weight = 0; int value  = 0; };

inline auto value(std::vector<int>& vals, size_t const i, Item total, int const max_weight, std::vector<Item> const& items) -> void {
    if (total.weight += items[i].weight, total.value += items[i].value; total.weight <= max_weight) {
        vals.push_back(total.value);

        for (auto next_i = i + 1; next_i < items.size(); ++next_i) {
            value(vals, next_i, total, max_weight, items);
        }
    }
}

inline auto maximum_value(int const max_weight, std::vector<Item> const& items) -> int {
    auto values = std::vector{0};

    for (auto i = 0U; i < items.size(); ++i) {
        value(values, i, {}, max_weight, items);
    }

    return *std::max_element(values.begin(), values.end());
}

} // namespace knapsack
