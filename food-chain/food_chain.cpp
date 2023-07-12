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
    Verse{
        "fly",
        "I don't know why she swallowed the fly. Perhaps she'll die.",
        "",
    },
    Verse{
        "spider",
        "It wriggled and jiggled and tickled inside her.",
        " that wriggled and jiggled and tickled inside her",
    },
    Verse{
        "bird",
        "How absurd to swallow a bird!",
        "",
    },
    Verse{
        "cat",
        "Imagine that, to swallow a cat!",
        "",
    },
    Verse{
        "dog",
        "What a hog, to swallow a dog!",
        "",
    },
    Verse{
        "goat",
        "Just opened her throat and swallowed a goat!",
        "",
    },
    Verse{
        "cow",
        "I don't know how she swallowed a cow!",
        "",
    },
    Verse{
        "horse",
        "She's dead, of course!",
        "",
    },
};

} // namespace

auto verse(int const n) -> std::string {
    if (n < 1 || 8 < n) {
        throw std::invalid_argument("'n' must be in the range [1,8]");
    }

    auto const to_index = [](int i) { return static_cast<unsigned>(i) - 1ul; };

    auto stream = std::stringstream{};

    {
        auto v = verses_list[to_index(n)];

        stream << "I know an old lady who swallowed a " << v.animal << ".\n"
               << v.exclamation << "\n";
    }

    if (n == 1 || n == 8) {
        return stream.str();
    }

    for (auto i = n; i > 1; --i) {
        stream << "She swallowed the " << verses_list[to_index(i)].animal
               << " to catch the " << verses_list[to_index(i - 1)].animal
               << verses_list[to_index(i - 1)].action << ".\n";
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
