#pragma once

#include <string>
#include <vector>

namespace secret_handshake {

auto commands(unsigned command) -> std::vector<std::string>;

} // namespace secret_handshake
