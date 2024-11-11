#include "rotational_cipher.h"

#include <algorithm>

namespace rotational_cipher {

namespace {

auto is_alpha(char const ch) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(ch)));
}

auto is_upper(char const ch) {
    return static_cast<bool>(std::isupper(static_cast<unsigned char>(ch)));
}

constexpr auto max_shift = 26;

struct Rotate {
    int& shift;

    auto operator()(char const c) const {
        if (is_alpha(c)) {
            auto const base          = is_upper(c) ? 'A' : 'a';
            auto const offset        = c - base;
            auto const wrapped_shift = (offset + shift) % max_shift;
            return static_cast<char>(base + wrapped_shift);
        }
        return c;
    }
};

} // namespace

auto rotate(std::string_view const input, int shift) -> std::string {
    auto output = std::string{input};
    std::transform(input.begin(), input.end(), output.begin(), Rotate{shift});
    return output;
}

} // namespace rotational_cipher
