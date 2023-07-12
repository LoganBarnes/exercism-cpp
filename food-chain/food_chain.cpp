#include "food_chain.h"

#include <array>
#include <sstream>

namespace food_chain {
namespace {

struct Verse {
    char const* animal;
    char const* exclamation;
    char const* action;
};

constexpr auto verses_list = std::array{
    Verse{"fly", "I don't know why she swallowed the fly. Perhaps she'll die.", ""},
    Verse{
        "spider",
        "It wriggled and jiggled and tickled inside her.",
        " that wriggled and jiggled and tickled inside her"},
    Verse{"bird", "How absurd to swallow a bird!", ""},
    Verse{"cat", "Imagine that, to swallow a cat!", ""},
    Verse{"dog", "What a hog, to swallow a dog!", ""},
    Verse{"goat", "Just opened her throat and swallowed a goat!", ""},
    Verse{"cow", "I don't know how she swallowed a cow!", ""},
    Verse{"horse", "She's dead, of course!", ""},
};

} // namespace

auto verse(int const n) -> std::string {
    if (n < 1 || 8 < n) {
        throw std::invalid_argument("'n' must be in the range [1,8]");
    }

    auto stream = std::stringstream{};

    auto const index      = static_cast<unsigned>(n) - 1ul;
    auto       verse_data = verses_list[index];

    stream << "I know an old lady who swallowed a " << verse_data.animal << ".\n"
           << verse_data.exclamation << "\n";

    if (n == 1 || n == 8) {
        return stream.str();
    }

    for (auto i = index; i > 0u; --i) {
        auto const current  = verses_list[i];
        auto const previous = verses_list[i - 1ul];

        stream << "She swallowed the " << current.animal << " to catch the "
               << previous.animal << previous.action << ".\n";
    }

    stream << verses_list[0].exclamation << "\n";
    return stream.str();
}

auto verses(int start, int end) -> std::string {
    auto stream = std::stringstream{};

    for (auto i = start; i <= end; ++i) {
        stream << verse(i) << "\n";
    }

    return stream.str();
}

auto sing() -> std::string {
    return verses(1, 8);
}

} // namespace food_chain
