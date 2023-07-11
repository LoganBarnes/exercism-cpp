#include "phone_number.h"

namespace phone_number {

phone_number::phone_number(std::string const& number) {
    // This is not super robust and will not detect
    // "1 (23) 4567-8901" or "(234) 5-67-89.01" as invalid.
    std::copy_if(
        number.begin(),
        number.end(),
        std::back_inserter(local_number_),
        [](auto c) {
            switch (c) {
                case '+': // All valid non-digit/whitespace characters.
                case '(':
                case ')':
                case '-':
                case '.':
                    return false;
                default:
                    if (std::isspace(c)) {
                        return false;
                    } else if (std::isdigit(c)) {
                        return true;
                    }
                    break;
            }
            throw std::domain_error("Invalid character: " + std::string(1, c));
        }
    );

    if (local_number_.size() == 11 && local_number_.front() == '1') {
        local_number_.erase(local_number_.begin());
    }

    auto const is_0_or_1 = [](char c) { return c == '0' || c == '1'; };

    auto const size = local_number_.size();

    switch (size) {
        case 10u:
            if (is_0_or_1(local_number_[size - 10u])) {
                throw std::domain_error("Invalid area code.");
            }
            area_code_ = local_number_.substr(0u, 3u);

            // fallthrough
        case 7u:
            if (is_0_or_1(local_number_[size - 7u])) {
                throw std::domain_error("Invalid exchange code.");
            }
            break;

        default:
            throw std::domain_error("Invalid phone number size.");
    }
}

auto phone_number::number() const -> std::string const& {
    return local_number_;
}

auto phone_number::area_code() const -> std::string const& {
    return area_code_;
}

phone_number::operator std::string() const {
    return "(" + area_code() + ") " + local_number_.substr(3, 3) + "-"
         + local_number_.substr(6, 4);
}

} // namespace phone_number
