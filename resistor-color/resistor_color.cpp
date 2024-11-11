#include "resistor_color.h"

#include <algorithm>

namespace resistor_color {

auto color_code(std::string_view color_name) -> int {
    auto const clrs = resistor_color::colors();
    if (auto const it = std::find(clrs.begin(), clrs.end(), color_name);
        it == clrs.end()) {
        return -1;
    } else {
        return static_cast<int>(it - clrs.begin());
    }
}

auto colors() -> std::vector<std::string> {
    return {
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
}

} // namespace resistor_color
