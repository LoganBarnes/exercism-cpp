#include "luhn.h"

namespace luhn {

auto valid(std::string const& s) -> bool {
    int sum   = 0;
    int count = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == ' ') {
            continue;
        }
        if (*it < '0' || *it > '9') {
            return false;
        }
        int digit = *it - '0';
        if (count % 2 == 1) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
        ++count;
    }
    return count > 1 && sum % 10 == 0;
}

} // namespace luhn
