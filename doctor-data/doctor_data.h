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
    Vessel replicate(std::string name) const;
    void   make_buster();
    bool   shoot_buster();

    std::string      name;
    int              generation;
    star_map::System current_system;
    int              busters;
};

std::string get_older_bob(Vessel const& bob, Vessel const& marv);
bool        in_the_same_system(Vessel const& marv, Vessel const& milo);

} // namespace heaven
