#include "isbn_verifier.h"

#include <cctype>

namespace isbn_verifier {

auto is_valid(std::string const& isbn) -> bool {
    auto digits = 0;
    auto sum    = 0;

    for (auto c : isbn) {
        if (std::isdigit(c)) {
            sum += (c - '0') * (10 - digits);
            ++digits;
        } else if (digits == 9 && c == 'X') {
            sum += 10;
            ++digits;
        } else if (c != '-') {
            return false;
        }
    }

    return digits == 10 && sum % 11 == 0;
}

} // namespace isbn_verifier
