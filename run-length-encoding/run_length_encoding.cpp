#include "run_length_encoding.h"

#include <charconv>
#include <sstream>

namespace run_length_encoding {
namespace {

[[nodiscard]] constexpr auto success() {
    return std::errc{};
}

auto add_char(std::ostream& os, char const c, size_t const count) {
    if (count > 1UL) {
        os << count;
    }
    os << c;
}

} // namespace

auto encode(std::string_view const input) -> std::string {
    if (input.empty()) {
        return "";
    }

    auto output     = std::stringstream{};
    auto char_count = 1UL;

    auto const input_size = input.size();
    for (auto i = 1UL; i < input_size; ++i) {
        if (input[i - 1UL] == input[i]) {
            ++char_count;

        } else {
            add_char(output, input[i - 1UL], char_count);
            char_count = 1UL;
        }
    }
    add_char(output, input.back(), char_count);

    return output.str();
}

auto decode(std::string_view const input) -> std::string {
    auto output = std::string{};

    auto const*       begin = input.data();
    auto const* const end   = input.data() + input.size();

    auto char_count = 1UL;

    while (begin != end) {
        auto const [next_char, error] = std::from_chars(begin, end, char_count);

        if (error == success()) {
            begin = next_char;

        } else {
            output += std::string(char_count, *begin);
            ++begin;
            char_count = 1UL;
        }
    }

    return output;
}

} // namespace run_length_encoding
