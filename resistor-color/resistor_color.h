#pragma once

#include <string>
#include <vector>

namespace resistor_color {

auto color_code(std::string_view color_name) -> int;

auto colors() -> std::vector<std::string>;

} // namespace resistor_color
