#include "robot_name.h"

#include <algorithm>
#include <iomanip>
#include <random>
#include <sstream>
#include <vector>

namespace robot_name {
namespace {

auto all_potential_robot_names() {
    // Always use the same generator to produce different
    // results each time this function is called.
    static auto rng = std::default_random_engine{};

    auto names  = std::vector<std::string>{};
    auto stream = std::stringstream{};

    for (auto i = 'A'; i <= 'Z'; ++i) {
        for (auto j = 'A'; j <= 'Z'; ++j) {
            for (auto k = 0; k <= 999; ++k) {
                stream << i << j << std::setfill('0') << std::setw(3) << k;
                names.emplace_back(stream.str());
                stream.str(""); // clear stream
            }
        }
    }

    // Randomize names
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
