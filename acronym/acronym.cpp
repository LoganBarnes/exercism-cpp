#include "acronym.h"

namespace acronym {
namespace {

auto is_space(char const c) {
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(c)));
}

auto is_punct(char const c) {
    return static_cast<bool>(std::ispunct(static_cast<unsigned char>(c)));
}

auto to_upper(char const c) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

} // namespace

auto acronym(std::string_view const input) -> std::string {
    auto result = std::string{};

    bool hit_whitespace = true;

    for (auto const c : input) {
        if (('-' == c) || acronym::is_space(c)) {
            hit_whitespace = true;

        } else if (hit_whitespace && (!acronym::is_punct(c))) {
            result += to_upper(c);
            hit_whitespace = false;

        } else {
            // Ignore all other characters.
        }
    }

    return result;
}

} // namespace acronym
