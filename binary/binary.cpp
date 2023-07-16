#include "binary.h"

namespace binary {

auto convert(std::string_view input) -> int {
    auto result = 0;

    for (auto const& c : input) {
        // Switches just seem cleaner to me.
        // Maybe I've been writing too much rust.
        switch (c) {
            case '0':
            case '1':
                result = (result << 1) | (c - '0');
                break;
            default:
                return 0;
        }
    }

    return result;
}

} // namespace binary
