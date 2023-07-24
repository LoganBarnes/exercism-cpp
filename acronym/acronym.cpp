#include "acronym.h"

#include <cctype>

namespace acronym {
namespace {

auto is_space(char c) {
    return static_cast<char>(std::isspace(static_cast<unsigned char>(c)));
}

auto is_punct(char c) {
    return static_cast<char>(std::ispunct(static_cast<unsigned char>(c)));
}

auto to_upper(char c) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

} // namespace

auto acronym(std::string_view input) -> std::string {
    auto result = std::string{};

    bool hit_whitespace = true;

    for (auto c : input) {
        if (c == '-' || is_space(c)) {
            hit_whitespace = true;
        } else if (hit_whitespace && !is_punct(c)) {
            result += to_upper(c);
            hit_whitespace = false;
        }
    }

    return result;
}

} // namespace acronym
