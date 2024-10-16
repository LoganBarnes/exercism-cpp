#pragma once

#include <string>
#include <vector>

namespace crypto_square {

class cipher {
public:
    explicit cipher(std::string text);

    [[nodiscard]] auto normalized_cipher_text() const -> std::string;

private:
    std::string text_;

    [[nodiscard]] auto normalize_plain_text() const -> std::string;
    [[nodiscard]] auto plain_text_segments() const -> std::string;
    [[nodiscard]] auto cipher_text() const -> std::string;
};

} // namespace crypto_square
