#pragma once

#include <string>
#include <unordered_set>

namespace allergies {

class allergy_test {
public:
    explicit allergy_test(unsigned score);

    auto is_allergic_to(std::string const& allergy) -> bool;

    auto get_allergies() const -> std::unordered_set<std::string> const&;

private:
    std::unordered_set<std::string> allergies_ = {};
};

} // namespace allergies
