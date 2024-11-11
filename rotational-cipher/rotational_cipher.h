#pragma once

#include <string>

namespace rotational_cipher {

auto rotate(std::string_view input, int shift) -> std::string;

} // namespace rotational_cipher
