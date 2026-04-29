#include "knapsack.h"

#include <unordered_set>

namespace knapsack {
namespace {

auto find_best_value(
    int const                         remaining_weight,
    int const                         current_value,
    std::vector<Item> const&          items,
    std::unordered_set<size_t> const& available_items
) -> int {
    if (remaining_weight < 0) {
        return 0;
    }
    if (remaining_weight == 0) {
        return current_value;
    }

    auto best_value = current_value;

    for (auto const i : available_items) {
        auto const& item = items[i];

        auto remaining_items = available_items;
        remaining_items.erase(i);

        auto const value = find_best_value(
            remaining_weight - item.weight,
            current_value + item.value,
            items,
            remaining_items
        );
        best_value = std::max(best_value, value);
    }

    return best_value;
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto       available_items = std::unordered_set<size_t>();
    auto const item_count      = items.size();
    for (auto i = 0U; i < item_count; ++i) {
        available_items.insert(i);
    }

    return find_best_value(max_weight, 0, items, available_items);
}

} // namespace knapsack
