#include "knapsack.h"

#include <algorithm>

namespace knapsack {
namespace {

auto compute_knapsacks(
    std::vector<int>&        values,
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
        values.push_back(total.value);

        for (auto i = index + 1; i < item_count; ++i) {
            compute_knapsacks(values, total, i, max_weight, items);
        }
    }
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto values = std::vector<int>{};

    for (auto i = 0U; i < items.size(); ++i) {
        compute_knapsacks(values, {}, i, max_weight, items);
    }

    if (values.empty()) {
        return 0;
    }

    return *std::max_element(values.begin(), values.end());
}

} // namespace knapsack
