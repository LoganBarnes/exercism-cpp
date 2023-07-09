#include "hexadecimal.h"

#include <algorithm>
#include <numeric>

namespace hexadecimal {

int convert(std::string const& hex) {
    if (!std::all_of(hex.begin(), hex.end(), isxdigit)) {
        return 0;
    }

    return std::accumulate(hex.begin(), hex.end(), 0, [](int acc, char c) {
        return acc * 16 + (isdigit(c) ? c - '0' : tolower(c) - 'a' + 10);
    });
}

} // namespace hexadecimal
