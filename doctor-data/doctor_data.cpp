#include "doctor_data.h"

namespace heaven {

Vessel::Vessel(
    std::string      vessel_name,
    int              vessel_generation,
    star_map::System vessel_current_system
)
    : name(std::move(vessel_name))
    , generation(vessel_generation)
    , current_system(vessel_current_system)
    , busters(0) {}

auto Vessel::replicate(std::string vessel_name) const -> Vessel {
    return Vessel(std::move(vessel_name), generation + 1, current_system);
}

auto Vessel::make_buster() -> void {
    busters++;
}

auto Vessel::shoot_buster() -> bool {
    if (busters > 0) {
        busters--;
        return true;
    }
    return false;
}

auto get_older_bob(Vessel const& v1, Vessel const& v2) -> std::string {
    if (v1.generation < v2.generation) {
        return v1.name;
    }
    return v2.name;
}

auto in_the_same_system(Vessel const& marv, Vessel const& milo) -> bool {
    return marv.current_system == milo.current_system;
}

} // namespace heaven
