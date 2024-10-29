#pragma once

#include <locale>
#include <string>
#include <string_view>

namespace acronym {

auto acronym(std::string_view input) -> std::string;

} // namespace acronym
