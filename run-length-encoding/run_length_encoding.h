#pragma once

#include <string>
#include <string_view>

namespace run_length_encoding {

auto encode(std::string_view input) -> std::string;

auto decode(std::string_view input) -> std::string;

} // namespace run_length_encoding
