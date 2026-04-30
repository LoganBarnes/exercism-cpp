#include "knapsack.h"

#include <algorithm>

namespace knapsack {
namespace {

struct IterationData {
    Item   total;
    size_t index;
};

auto compute_values_recursive(
    std::vector<int>&        values,
    IterationData            data,
    int const                max_weight,
    std::vector<Item> const& items
) {
    auto const item_count = items.size();

    if (data.index >= item_count) {
        return;
    }
    auto const& item = items[data.index];

    data.total.weight += item.weight;
    data.total.value += item.value;

    if (data.total.weight <= max_weight) {
        values.push_back(data.total.value);

        for (auto i = data.index + 1; i < item_count; ++i) {
            compute_values_recursive(
                values, {data.total, i}, max_weight, items
            );
        }
    }
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto values = std::vector<int>{};

    for (auto i = 0U; i < items.size(); ++i) {
        compute_values_recursive(values, {{}, i}, max_weight, items);
    }

    if (values.empty()) {
        return 0;
    }

    return *std::max_element(values.begin(), values.end());
}

} // namespace knapsack
