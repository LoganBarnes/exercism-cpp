#include "raindrops.h"

#include <numeric>
#include <vector>

namespace raindrops {

auto convert(int input) -> std::string {
    auto sounds = std::vector<std::pair<int, std::string>>{
        {3, "Pling"},
        {5, "Plang"},
        {7, "Plong"},
    };

    if (auto result = std::accumulate(
            sounds.begin(),
            sounds.end(),
            std::string{},
            [input](auto result, auto factor_and_sound) {
                auto [factor, sound] = factor_and_sound;
                if (input % factor == 0) {
                    return result + sound;
                } else {
                    return result;
                }
            }
        );
        !result.empty()) {
        return result;
    } else {
        return std::to_string(input);
    }
}

} // namespace raindrops
