#include "allergies.h"

#include <array>

namespace allergies {

allergy_test::allergy_test(unsigned int score) {
    static constexpr auto allergies = std::array{
        "eggs",
        "peanuts",
        "shellfish",
        "strawberries",
        "tomatoes",
        "chocolate",
        "pollen",
        "cats",
    };

    std::copy_if(
        allergies.begin(),
        allergies.end(),
        std::inserter(allergies_, allergies_.end()),
        [score](auto const& allergy) {
            return score & (1u << (&allergy - allergies.data()));
        }
    );
}

auto allergy_test::is_allergic_to(std::string const& allergy) -> bool {
    return allergies_.find(allergy) != allergies_.end();
}

auto allergy_test::get_allergies() const
    -> std::unordered_set<std::string> const& {
    return allergies_;
}

} // namespace allergies
