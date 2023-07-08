#include "atbash_cipher.h"

namespace atbash_cipher {

// I didn't even look at the tests. I simply typed "auto encode"
// and "auto decode" and GitHub Copilot did the rest. :O
// I did make minor style changes afterward.
auto encode(std::string const& text) -> std::string {
    auto result = std::string{};
    auto count  = 0;

    for (auto const& c : text) {
        if (std::isalnum(c)) {
            result += std::isalpha(c) ? 'a' + 'z' - std::tolower(c) : c;

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
