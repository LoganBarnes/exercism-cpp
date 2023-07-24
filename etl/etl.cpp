#include "etl.h"

#include <algorithm>
#include <cctype>

namespace etl {

// https://en.cppreference.com/w/cpp/string/byte/tolower#Notes
auto to_lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

auto transform(std::map<int, std::vector<char>> const& old)
    -> std::map<char, int> {

    auto result = std::map<char, int>{};

    for (auto const& [score, letters] : old) {
        for (auto const& letter : letters) {
            result[to_lower(letter)] = score;
        }
    }

    return result;
}

} // namespace etl
