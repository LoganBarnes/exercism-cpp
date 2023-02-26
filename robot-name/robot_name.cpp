#include "robot_name.h"

#include <algorithm>
#include <cassert>
#include <random>
#include <vector>

namespace robot_name {
namespace {

auto all_potential_robot_names() {
    constexpr auto total_name_count = 26UL * 26UL * 1'000UL;

    // Generate all possible names

    auto names = std::vector<std::string>{};
    names.reserve(total_name_count);

    // Convert string to robot name.
    auto name = std::string{"00000"};
    for (name[0] = 'A'; name[0] <= 'Z'; ++name[0]) {
        for (name[1] = 'A'; name[1] <= 'Z'; ++name[1]) {
            for (auto i = 0; i <= 999; ++i) {
                std::snprintf(name.data() + 2, 4, "%.3i", i);
                names.emplace_back(name);
            }
        }
    }
    assert(names.size() == total_name_count);

    // Randomize the order of the names

    // Always use the same generator to produce different
    // results each time this function is called.
    static auto rng = std::default_random_engine{};
    std::shuffle(std::begin(names), std::end(names), rng);

    return names;
}

} // namespace

robot::robot() {
    reset();
}

auto robot::reset() -> void {
    // Potential names are global so no two robots have the same name.
    static auto potential_names = all_potential_robot_names();
    if (potential_names.empty()) {
        potential_names = all_potential_robot_names();
    }

    name_ = potential_names.back();
    potential_names.pop_back();
}

auto robot::name() const -> std::string const& {
    return name_;
}

} // namespace robot_name
