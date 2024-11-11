#include "zebra_puzzle.h"

#include <array>
#include <functional>
#include <variant>
#include <vector>

namespace zebra_puzzle {
namespace {

struct House {
    std::string nationality = {};
    std::string color       = {};
    int         location    = {};
    std::string pet         = {};
    std::string drink       = {};
    std::string hobby       = {};
};

struct HousePossibilities {
    std::vector<std::string> nationality = {};
    std::vector<std::string> color       = {};
    std::vector<int>         location    = {};
    std::vector<std::string> pet         = {};
    std::vector<std::string> drink       = {};
    std::vector<std::string> hobby       = {};
};

auto right_house(House const& house) -> HousePossibilities {
    return {.location = {house.location + 1}};
}

auto adjacent_house(House const& house) -> HousePossibilities {
    if (house.location == 0) {
        return {.location = {1}};
    } else if (house.location == 4) {
        return {.location = {3}};
    } else {
        return {.location = {house.location - 1, house.location + 1}};
    }
}

using Functor = std::function<HousePossibilities(House)>;

struct Constraint {
    House                                     input  = {};
    std::variant<HousePossibilities, Functor> output = {};
};

struct Spec {
    House   inputs;
    Functor outputs;
};

using Const = std::variant<House, Spec>;

auto const constraints = std::vector<Constraint>{
    {{.nationality = "English"}, HousePossibilities{.color = {"Red"}}},
    {{.nationality = "English"}, HousePossibilities{.color = {"Red"}}},
    {{.nationality = "Spaniard"}, HousePossibilities{.pet = {"Dog"}}},
    {{.color = "Green"}, HousePossibilities{.drink = {"Coffee"}}},
    {{.nationality = "Ukrainian"}, HousePossibilities{.drink = {"Tea"}}},
    {{.color = "Green"}, right_house},
    {{.pet = "Snail"}, HousePossibilities{.hobby = {"Dancing"}}},
    {{.color = "Yellow"}, HousePossibilities{.hobby = {"Painting"}}},
    {{.location = 2}, HousePossibilities{.drink = {"Milk"}}},
    {{.nationality = "Norwegian"}, HousePossibilities{.location = {0}}},
    {{.hobby = "Reading"}, adjacent_house},
    {{.drink = "Orange"}, HousePossibilities{.hobby = {"Football"}}},
    {{.nationality = "Japanese"}, HousePossibilities{.hobby = {"Chess"}}},
};

class Houses {
public:
    auto apply(Constraint const& constraint) -> bool;

    auto find(House const& house) const -> House;

private:
    std::vector<House> houses_;
};

auto Houses::apply([[maybe_unused]] Constraint const& constraint) -> bool {
    return false;
}

auto Houses::find(House const& house) const -> House {
    return house;
}

} // namespace

auto solve() -> Solution {
    auto houses = Houses{};

    auto state_changed = false;
    do {
        state_changed = false;

        for (auto const& constraint : constraints) {
            state_changed = houses.apply(constraint) || state_changed;
        }
    } while (state_changed);

    return {
        .drinksWater = houses.find(House{.drink = "Water"}).nationality,
        .ownsZebra   = houses.find(House{.pet = "Zebra"}).nationality,
    };
}

} // namespace zebra_puzzle
