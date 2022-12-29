#include "raindrops.h"

namespace raindrops {

auto convert(int input) -> std::string {
    auto result = std::string{};

    for (auto [factor, message] : {
             std::make_pair(3, "Pling"),
             std::make_pair(5, "Plang"),
             std::make_pair(7, "Plong"),
         }) {
        if (input % factor == 0) {
            result += message;
        }
    }

    if (result.empty()) {
        return std::to_string(input);
    } else {
        return result;
    }
}

} // namespace raindrops
