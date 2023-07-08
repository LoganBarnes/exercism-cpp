#pragma once

#include <string>

namespace atbash_cipher {

auto encode(std::string const& text) -> std::string;
auto decode(std::string const& text) -> std::string;

}  // namespace atbash_cipher
