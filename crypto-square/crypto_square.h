#pragma once

#include <string>

namespace crypto_square {

class cipher {
public:
    explicit cipher(std::string text);

    auto normalize_plain_text() const -> std::string;
    auto plain_text_segments() const -> std::vector<std::string>;
    auto cipher_text() const -> std::string;
    auto normalized_cipher_text() const -> std::string;

private:
    std::string text_;
};

} // namespace crypto_square
