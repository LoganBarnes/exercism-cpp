#pragma once

#include <string>

namespace star_map {

enum class System {
    Sol,
    AlphaCentauri,
    BetaHydri,
    DeltaEridani,
    EpsilonEridani,
    Omicron2Eridani
};

} // namespace star_map

namespace heaven {

class Vessel {
public:
    explicit Vessel(
        std::string      name,
        int              generation,
        star_map::System current_system = star_map::System::Sol
    );
    auto replicate(std::string name) const -> Vessel;
    auto make_buster() -> void;
    auto shoot_buster() -> bool;

    std::string      name;
    int              generation;
    star_map::System current_system;
    int              busters;
};

auto get_older_bob(Vessel const& bob, Vessel const& marv) -> std::string;
auto in_the_same_system(Vessel const& marv, Vessel const& milo) -> bool;

} // namespace heaven
