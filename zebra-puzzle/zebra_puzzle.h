#pragma once

#include <string>

namespace zebra_puzzle {

struct Solution {
    std::string drinksWater;
    std::string ownsZebra;
};

auto solve() -> Solution;

} // namespace zebra_puzzle
