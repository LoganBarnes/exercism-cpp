#include "secret_handshake.h"

#include <algorithm>
#include <array>

namespace secret_handshake {

auto commands(unsigned command) -> std::vector<std::string> {
    static constexpr auto actions = std::array{
        "wink",
        "double blink",
        "close your eyes",
        "jump",
    };

    auto result = std::vector<std::string>{};

    for (auto i = 0u; i < actions.size(); ++i) {
        if (command & (1u << i)) {
            result.push_back(actions[i]);
        }
    }

    if (command & (1u << actions.size())) {
        std::reverse(result.begin(), result.end());
    }

    return result;
}

} // namespace secret_handshake
