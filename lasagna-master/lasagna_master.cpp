#include "lasagna_master.h"

#include <algorithm>
#include <iterator>
#include <string_view>

namespace lasagna_master {
namespace {

struct IsQuestionMark {
    auto operator()(std::string_view ingredient) const {
        return ingredient == "?";
    }
};

struct Scale {
    double factor = 1.0;

    auto operator()(double const quantity) const { return quantity * factor; }
};

} // namespace

auto preparationTime(Ingredients const& layers) -> int {
    return preparationTime(layers, 2);
}

auto preparationTime(Ingredients const& layers, int time_per_layer) -> int {
    return static_cast<int>(layers.size()) * time_per_layer;
}

auto quantities(Ingredients const& layers) -> amount {
    constexpr auto grams_per_noodle_layer = 50;
    constexpr auto liters_per_sauce_layer = 0.2;

    return amount{
        // .noodles =
        static_cast<int>(std::count(layers.begin(), layers.end(), "noodles"))
            * grams_per_noodle_layer,
        // .sauce =
        static_cast<double>(std::count(layers.begin(), layers.end(), "sauce"))
            * liters_per_sauce_layer,
    };
}

auto addSecretIngredient(Ingredients& myList, Ingredients const& friendsList)
    -> void {
    return addSecretIngredient(myList, friendsList.back());
}

auto addSecretIngredient(Ingredients& myList, std::string const& ingredient)
    -> void {
    std::replace_if(myList.begin(), myList.end(), IsQuestionMark{}, ingredient);
}

auto scaleRecipe(Quantities const& quantities_for_two, double desired_portions)
    -> Quantities {

    auto quantities = Quantities{};
    quantities.reserve(quantities_for_two.size());

    std::transform(
        quantities_for_two.begin(),
        quantities_for_two.end(),
        std::back_inserter(quantities),
        Scale{desired_portions / 2.0}
    );

    return quantities;
}

} // namespace lasagna_master
