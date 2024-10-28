#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

using Ingredients = std::vector<std::string>;
using Quantities  = std::vector<double>;

struct amount {
    // grams
    int noodles = 0;
    // liters
    double sauce = 0.0;
};

/// \brief Calculate the preparation time (in minutes) for a
///        lasagna which takes 2 min to prepare each layer.
auto preparationTime(Ingredients const& layers) -> int;

/// \brief Calculate the preparation time (in minutes) for a lasagna.
auto preparationTime(Ingredients const& layers, int min_per_layer) -> int;

/// \brief Calculate the amount of noodles and sauce needed for a lasagna.
auto quantities(Ingredients const& layers) -> amount;

/// \brief Add a friend's secret ingredient to the lasagna.
auto addSecretIngredient(Ingredients& myList, Ingredients const& friendsList)
    -> void;

/// \brief Add the family secret ingredient to the lasagna.
auto addSecretIngredient(Ingredients& myList, std::string const& ingredient)
    -> void;

/// \brief Determine the quantities of ingredients needed to
///        produce the desired number of portions.
auto scaleRecipe(Quantities const& quantities_for_two, double desired_portions)
    -> Quantities;

} // namespace lasagna_master
