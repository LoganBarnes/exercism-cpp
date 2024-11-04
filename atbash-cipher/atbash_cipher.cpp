#include "atbash_cipher.h"

namespace atbash_cipher {
namespace {

auto is_alnum(char const ch) {
    return static_cast<bool>(std::isalnum(static_cast<unsigned char>(ch)));
}

auto is_alpha(char const ch) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(ch)));
}

auto to_lower(char const ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

} // namespace

// I didn't even look at the tests. I simply typed "auto encode"
// and "auto decode" and GitHub Copilot did the rest. :O
// I did make minor style changes afterward.
auto encode(std::string const& text) -> std::string {
    auto result = std::string{};
    auto count  = 0;

    for (auto const& c : text) {
        if (is_alnum(c)) {
            result += is_alpha(c) ? 'a' + 'z' - to_lower(c) : c;

            if (++count % 5 == 0) {
                result += ' ';
            }
        }
    }

    if (result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

auto decode(std::string const& text) -> std::string {
    auto result = std::string{};

    for (auto const& c : text) {
        if (std::isalnum(c)) {
            result += std::isalpha(c) ? 'a' + 'z' - std::tolower(c) : c;
        }
    }
    return result;
}

} // namespace atbash_cipher
