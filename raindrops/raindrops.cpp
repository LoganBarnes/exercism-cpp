#include "raindrops.h"

namespace raindrops {

auto convert(int input) -> std::string {
    auto result = std::string{};

    if (input % 3 == 0) {
        result += "Pling";
    }
    if (input % 5 == 0) {
        result += "Plang";
    }
    if (input % 7 == 0) {
        result += "Plong";
    }

    if (result.empty()) {
        return std::to_string(input);
    } else {
        return result;
    }
}

} // namespace raindrops
