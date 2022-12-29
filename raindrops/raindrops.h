#pragma once

#include <string>

namespace raindrops {

inline auto convert(int input) -> std::string {
    auto p      = std::make_pair<int, std::string>;
    auto result = std::string{};

    for (auto [f, s] : {p(3, "Pling"), p(5, "Plang"), p(7, "Plong")}) {
        if (input % f == 0) { result += s; }
    }

    return result.empty() ? std::to_string(input) : result;
}

} // namespace raindrops
