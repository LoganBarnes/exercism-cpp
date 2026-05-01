#include "power_of_troy.h"

namespace troy {

auto give_new_artifact(human& human, std::string artifact_name) -> void {
    human.possession = std::make_unique<artifact>(std::move(artifact_name));
}

auto exchange_artifacts(std::unique_ptr<artifact>& lhs, std::unique_ptr<artifact>& rhs) -> void {
    std::swap(lhs, rhs);
}

auto manifest_power(human& human, std::string power_name) -> void {
    human.own_power = std::make_shared<power>(std::move(power_name));
}

auto use_power(human const& caster, human& target) -> void {
    target.influenced_by = caster.own_power;
}

auto power_intensity(human const& human) -> long {
    return human.own_power ? human.own_power.use_count() : 0L;
}

} // namespace troy
