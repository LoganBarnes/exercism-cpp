#pragma once

#include <memory>
#include <string>

namespace troy {

struct artifact {
    std::string name = {};
};

struct power {
    std::string effect = {};
};

struct human {
    std::unique_ptr<artifact> possession    = nullptr;
    std::shared_ptr<power>    own_power     = nullptr;
    std::shared_ptr<power>    influenced_by = nullptr;
};

auto give_new_artifact(human& human, std::string artifact_name) -> void;

auto exchange_artifacts(std::unique_ptr<artifact>& lhs, std::unique_ptr<artifact>& rhs) -> void;

auto manifest_power(human& human, std::string power_name) -> void;

auto use_power(human const& caster, human& target) -> void;

auto power_intensity(human const& human) -> long;

} // namespace troy
