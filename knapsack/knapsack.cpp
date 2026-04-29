#include "knapsack.h"

#include <iostream>

namespace knapsack {
namespace {

using Knapsacks = std::vector<Item>;

auto compute_knapsacks(
    Knapsacks&               knapsacks,
    Item                     total,
    size_t const             index,
    int const                max_weight,
    std::vector<Item> const& items
) {
    auto const item_count = items.size();

    if (index >= item_count) {
        return;
    }
    auto const& item = items[index];

    total.weight += item.weight;
    total.value += item.value;

    if (total.weight <= max_weight) {
        knapsacks.push_back(total);

        for (auto i = index + 1; i < item_count; ++i) {
            compute_knapsacks(knapsacks, total, i, max_weight, items);
        }
    }
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto knapsacks = Knapsacks{};

    for (auto i = 0U; i < items.size(); ++i) {
        compute_knapsacks(knapsacks, {}, i, max_weight, items);
    }

    if (knapsacks.empty()) {
        return 0;
    }

    return std::max_element(knapsacks.begin(), knapsacks.end())->value;
}

} // namespace knapsack
