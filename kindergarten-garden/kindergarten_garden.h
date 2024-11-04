#pragma once

#include <array>
#include <string_view>

namespace kindergarten_garden {

enum class Plants : char {
    clover   = 'C',
    grass    = 'G',
    violets  = 'V',
    radishes = 'R',
};

inline auto plants(std::string_view const diagram, std::string_view const student) {
    auto const index  = static_cast<size_t>(student.front() - 'A');
    auto const offset = (diagram.size() / 2UL) + 1UL;

    return std::array{
        static_cast<Plants>(diagram[(index * 2UL) + 0UL]),
        static_cast<Plants>(diagram[(index * 2UL) + 1UL]),
        static_cast<Plants>(diagram[(index * 2UL) + 0UL + offset]),
        static_cast<Plants>(diagram[(index * 2UL) + 1UL + offset]),
    };
}

} // namespace kindergarten_garden
