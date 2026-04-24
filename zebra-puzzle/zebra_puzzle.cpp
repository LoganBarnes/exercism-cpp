#include "zebra_puzzle.h"

#include <algorithm>
#include <array>
#include <functional>
#include <map>
#include <ranges>
#include <set>
#include <variant>
#include <vector>

namespace zebra_puzzle {
namespace {

constexpr auto* nationality = "nationality";
constexpr auto* color       = "color";
constexpr auto* pet         = "pet";
constexpr auto* location    = "location";
constexpr auto* drink       = "drink";
constexpr auto* hobby       = "hobby";

using HouseElement = std::pair<char const*, std::string>;
using ElementSet   = std::set<HouseElement>;

struct House {
    std::map<char const*, std::string>           elements;
    std::map<char const*, std::set<std::string>> potential_elements;
};

struct Constraint {
    HouseElement                                   house;
    std::function<ElementSet(HouseElement const&)> constraint;
};

auto right_house(HouseElement const& house) -> ElementSet {
    if (auto const number = std::stoi(house.second); number < 5) {
        return ElementSet{{location, std::to_string(number + 1)}};
    } else {
        throw std::domain_error("House location out of range");
    }
}

auto adjacent_house(House const& house) -> ElementSet {
    if (house.elements.contains())
    auto const number = std::stoi(house.second);

    auto result = std::set<HouseElement>();
    if (number > 1) {
        result.emplace(location, std::to_string(number - 1));
    }
    if (number < 5) {
        result.emplace(location, std::to_string(number + 1));
    }
    return result;
}

auto const constraints = std::vector<Constraint>{
    {
        {nationality, "English"},
        [](auto const&) { return ElementSet{{color, "Red"}}; },
    },
    {
        {nationality, "English"},
        [](auto const&) { return ElementSet{{color, "Red"}}; },
    },
    {
        {nationality, "Spaniard"},
        [](auto const&) { return ElementSet{{pet, "Dog"}}; },
    },
    {
        {color, "Green"},
        [](auto const&) { return ElementSet{{drink, "Coffee"}}; },
    },
    {
        {nationality, "Ukrainian"},
        [](auto const&) { return ElementSet{{drink, "Tea"}}; },
    },
    {{color, "Green"}, right_house},
    {
        {pet, "Snail"},
        [](auto const&) { return ElementSet{{hobby, "Dancing"}}; },
    },
    {
        {color, "Yellow"},
        [](auto const&) { return ElementSet{{hobby, "Painting"}}; },
    },
    {
        {location, "3"},
        [](auto const&) { return ElementSet{{drink, "Milk"}}; },
    },
    {
        {nationality, "Norwegian"},
        [](auto const&) { return ElementSet{{location, "1"}}; },
    },
    {{hobby, "Reading"}, adjacent_house},
    {
        {drink, "Orange"},
        [](auto const&) { return ElementSet{{hobby, "Football"}}; },
    },
    {
        {nationality, "Japanese"},
        [](auto const&) { return ElementSet{{hobby, "Chess"}}; },
    },
};

class Houses {
public:
    auto apply(Constraint const& constraint) -> bool;

    auto find(HouseElement const& house) -> House&;

private:
    std::vector<House> houses_;
};

auto Houses::apply([[maybe_unused]] Constraint const& constraint) -> bool {
    auto& house = find(constraint.house);

    auto const c = constraint.second(

    return false;
}

struct Contains {
    HouseElement const& element;

    auto operator()(House const& house) const {
        return house.elements.contains(element.first)
            && house.elements.at(element.first) == element.second;
    }
};

auto Houses::find(HouseElement const& element) -> House& {
    if (auto const iter = std::ranges::find_if(houses_, Contains{element});
        iter != houses_.end()) {
        return *iter;
    }
    houses_.push_back({.elements = {element}, .potential_elements = {}});
    return houses_.back();
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
        .drinksWater = houses.find({drink, "Water"}).elements.at(nationality),
        .ownsZebra   = houses.find({pet, "Zebra"}).elements.at(nationality),
    };
}

} // namespace zebra_puzzle
