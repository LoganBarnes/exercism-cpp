#include "resistor_color_duo.h"

#include <algorithm>
#include <array>

namespace resistor_color_duo {
namespace {

auto constexpr colors_words = std::array{
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white",
};

auto value(std::string const& color) -> int {
    if (auto const it
        = std::find(colors_words.begin(), colors_words.end(), color);
        it == colors_words.end()) {
        return -1;
    } else {
        return static_cast<int>(it - colors_words.begin());
    }
}

} // namespace

auto value(std::vector<std::string> const& colors) -> int {
    auto result = 0;

    auto const size = std::min(colors.size(), 2UL);
    for (auto i = 0UL; i < size; ++i) {
        result = (result * 10) + value(colors[i]);
    }
    return result;
}

} // namespace resistor_color_duo
