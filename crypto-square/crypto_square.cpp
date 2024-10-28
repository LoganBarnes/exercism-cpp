#include "crypto_square.h"

#include <algorithm>
#include <cctype>
#include <cmath>

namespace crypto_square {
namespace {

auto to_lower(char const ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

auto not_word(char const ch) {
    auto const uch = static_cast<unsigned char>(ch);
    return std::isspace(uch) || std::ispunct(uch);
}

} // namespace

cipher::cipher(std::string text) : text_(std::move(text)) {}

auto cipher::normalize_plain_text() const -> std::string {
    auto text = text_;
    text.erase(std::remove_if(text.begin(), text.end(), not_word), text.end());
    std::transform(text.begin(), text.end(), text.begin(), to_lower);
    return text;
}

auto cipher::plain_text_segments() const -> std::vector<std::string> {
    auto text = normalize_plain_text();

    auto const root = std::sqrt(text.size());
    auto const cols = static_cast<size_t>(std::ceil(root));

    auto result = std::vector<std::string>{};

    while (!text.empty()) {
        auto const sub_size = static_cast<ssize_t>(std::min(cols, text.size()));

        result.emplace_back(text.begin(), text.begin() + sub_size);

        text = {text.begin() + sub_size, text.end()};
    }

    return result;
}

auto cipher::normalized_cipher_text() const -> std::string {
    auto const segments = plain_text_segments();

    if (segments.empty()) {
        return "";
    }

    auto const rows = segments.size();
    auto const cols = segments.front().size();

    auto result = std::string(rows * cols + cols - 1UL, ' ');

    for (auto r = 0UL; r < segments.size(); ++r) {
        for (auto c = 0UL; c < segments[r].size(); ++c) {
            result[c * (rows + 1UL) + r] = segments[r][c];
        }
    }

    return result;
}

} // namespace crypto_square
