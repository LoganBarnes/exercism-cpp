#pragma once

#include <string>
#include <vector>

namespace crypto_square {

class cipher {
public:
    explicit cipher(std::string text);

    [[nodiscard]] auto normalize_plain_text() const -> std::string;
    [[nodiscard]] auto plain_text_segments() const -> std::vector<std::string>;
    [[nodiscard]] auto normalized_cipher_text() const -> std::string;

private:
    std::string text_;
};

} // namespace crypto_square
