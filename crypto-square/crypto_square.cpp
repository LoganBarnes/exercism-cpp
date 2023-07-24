#include "crypto_square.h"

#include <algorithm>
#include <cctype>
#include <cmath>

namespace crypto_square {
namespace {

auto to_lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

auto not_word(char ch) {
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
    auto const text = normalize_plain_text();

    auto const root   = std::sqrt(text.size());
    auto const rows   = static_cast<size_t>(std::floor(root));
    auto const cols   = static_cast<size_t>(std::ceil(root));
    auto       result = std::vector<std::string>(rows, std::string(cols, ' '));

    for (auto i = 0u; i < result.size(); ++i) {
        auto const sub_size = std::min(cols, text.size() - i * cols);
        result[i]           = text.substr(i * cols, sub_size);
    }

    return result;
}

auto cipher::cipher_text() const -> std::string {
    auto const segments = plain_text_segments();

    if (segments.empty()) {
        return "";
    }

    auto const rows = segments.size();
    auto const cols = segments.front().size();

    auto result = std::string{};

    for (auto c = 0u; c < cols; ++c) {
        for (auto r = 0u; r < rows; ++r) {
            if (c < segments[r].size()) {
                result += segments[r][c];
            }
        }
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

    auto result = std::string(rows * cols + cols - 1, ' ');

    for (auto r = 0u; r < segments.size(); ++r) {
        for (auto c = 0u; c < segments[r].size(); ++c) {
            result[c * (rows + 1) + r] = segments[r][c];
        }
    }

    return result;
}

} // namespace crypto_square
