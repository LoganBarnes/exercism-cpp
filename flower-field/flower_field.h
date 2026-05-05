#pragma once

#include <string>
#include <vector>

namespace flower_field {

using Field = std::vector<std::string>;

auto annotate(Field const& field) -> Field;

} // namespace flower_field
