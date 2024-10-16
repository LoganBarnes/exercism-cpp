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

auto cipher::plain_text_segments() const -> std::string {
    auto const text = normalize_plain_text();

    auto const root   = std::sqrt(text.size());
    auto const rows   = static_cast<size_t>(std::ceil(root));
    auto const cols   = static_cast<size_t>(std::ceil(root));
    auto       result = std::string(cols * rows, ' ');

    for (auto r = 0U; r < rows; ++r) {
        auto const sub_size = std::min(cols, text.size() - r * cols);
        auto const substring = text.substr(r * cols, sub_size);
        std::copy(substring.begin(), substring.end(), result.begin() + static_cast<ssize_t>(r * cols));
    }

    return result;
}

auto cipher::cipher_text() const -> std::string {
    auto const segments = plain_text_segments();
//
//    if (segments.empty()) {
//        return "";
//    }
//
//    auto const rows = segments.size();
//    auto const cols = segments.front().size();
//
//    auto result = std::string{};
//
//    for (auto c = 0u; c < cols; ++c) {
//        for (auto r = 0u; r < rows; ++r) {
//            if (c < segments[r].size()) {
//                result += segments[r][c];
//            }
//        }
//    }

    return segments;
}

auto cipher::normalized_cipher_text() const -> std::string {
    auto const segments = plain_text_segments();

//    if (segments.empty()) {
//        return "";
//    }
//
//    auto const rows = segments.size();
//    auto const cols = segments.front().size();
//
//    auto result = std::string(rows * cols + cols - 1, ' ');
//
//    for (auto r = 0u; r < segments.size(); ++r) {
//        for (auto c = 0u; c < segments[r].size(); ++c) {
//            result[c * (rows + 1) + r] = segments[r][c];
//        }
//    }

    return segments;
}

} // namespace crypto_square
