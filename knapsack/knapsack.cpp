#include "knapsack.h"

#include <iostream>

namespace knapsack {
namespace {

using Key    = std::vector<bool>;
using Totals = std::unordered_map<std::vector<bool>, Item>;

int iter = 0;

auto best_sub_sack(
    Totals&                  totals,
    Key                      key,
    Item                     total,
    size_t const             index,
    int const                max_weight,
    std::vector<Item> const& items
) {
    auto const item_count = items.size();

    if (index >= item_count) {
        return;
    }
    key[index] = true;

    // unused?
    if (totals.find(key) != totals.end()) {
        return;
    }

    ++iter;

    auto const& item = items[index];

    total.weight += item.weight;
    total.value += item.value;

    if (total.weight <= max_weight) {
        totals[key] = total;

        for (auto i = index + 1; i < item_count; ++i) {
            best_sub_sack(totals, key, total, i, max_weight, items);
        }
    }
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto const key = std::vector<bool>(items.size(), false);

    auto totals = Totals{};
    iter = 0;

    for (auto i = 0U; i < items.size(); ++i) {
        best_sub_sack(totals, key, {}, i, max_weight, items);
    }

    std::cout << items.size() << ": " << iter << std::endl;

    auto best_value = 0;
    for (auto const& total : totals) {
        best_value = std::max(best_value, total.second.value);
    }

    return best_value;
}

} // namespace knapsack
