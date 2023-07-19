#include "scrabble_score.h"

#include <cctype>

namespace scrabble_score {

auto score(std::string_view word) -> int {
    auto total = 0;
    for (auto c : word) {
        // Casting to unsigned char as per the recommendations here:
        // https://en.cppreference.com/w/cpp/string/byte/toupper#Notes.
        switch (std::toupper(static_cast<unsigned char>(c))) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'L':
            case 'N':
            case 'R':
            case 'S':
            case 'T':
                total += 1;
                break;
            case 'D':
            case 'G':
                total += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                total += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                total += 4;
                break;
            case 'K':
                total += 5;
                break;
            case 'J':
            case 'X':
                total += 8;
                break;
            case 'Q':
            case 'Z':
                total += 10;
                break;
            default:
                break;
        }
    }
    return total;
}

} // namespace scrabble_score
