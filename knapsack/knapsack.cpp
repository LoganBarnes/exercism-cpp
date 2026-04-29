#include "knapsack.h"

namespace knapsack {
namespace {

struct TreeNode {
    Item                  totals   = {};
    std::vector<TreeNode> children = {};
};

auto add_children(
    int const max_weight, TreeNode& node, std::vector<Item> const& items
) -> void {
    auto const num_items = items.size();
    node.children.reserve(num_items);

    for (auto i = 0U; i < num_items; ++i) {

        auto child_node   = TreeNode{};
        child_node.totals = node.totals;
        child_node.totals.value += items[i].value;
        child_node.totals.weight += items[i].weight;

        // Weights are strictly positive so we don't need to
        // check more items if weight == max_weight.
        if (child_node.totals.weight < max_weight) {
            node.children.push_back(child_node);

            auto items_copy = items;
            items_copy.erase(items_copy.begin() + i);

            add_children(max_weight, node.children.back(), items_copy);
        }
    }
}

auto find_best_value(TreeNode const& node) -> int {
    auto best_value = node.totals.value;

    for (auto const& child : node.children) {
        best_value = std::max(best_value, find_best_value(child));
    }

    return best_value;
}

} // namespace

auto maximum_value(int const max_weight, std::vector<Item> const& items)
    -> int {
    auto tree = TreeNode{};
    add_children(max_weight, tree, items);
    return find_best_value(tree);
}

} // namespace knapsack
