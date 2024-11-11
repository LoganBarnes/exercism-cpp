#include "minesweeper.h"

#include <algorithm>

namespace minesweeper {
namespace {

class MineField {
public:
    std::vector<std::string> const& field;

    size_t rows = field.size();
    size_t cols = (field.empty() ? 0UL : field.front().size());

    [[nodiscard]] auto count(size_t const row, size_t const col) const {
        auto result = 0;

        auto const begin_row = std::max(row, 1UL) - 1UL;
        auto const begin_col = std::max(col, 1UL) - 1UL;
        auto const end_row   = std::min(row + 2UL, rows);
        auto const end_col   = std::min(col + 2UL, cols);

        for (auto ri = begin_row; ri < end_row; ++ri) {
            for (auto ci = begin_col; ci < end_col; ++ci) {
                if (((ri != row) || (ci != col)) && field[ri][ci] == '*') {
                    ++result;
                }
            }
        }

        return result;
    }
};

} // namespace

auto annotate(std::vector<std::string> const& input
) -> std::vector<std::string> {
    auto const field = MineField{input};

    auto output = input;

    for (auto row = 0UL; row < field.rows; ++row) {
        for (auto col = 0UL; col < field.cols; ++col) {
            auto ch = input[row][col];

            if (ch == '*') {
                // No need to do anything for mines

            } else if (auto const count = field.count(row, col)) {
                ch = static_cast<char>('0' + count);
            }
            output[row][col] = ch;
        }
    }

    return output;
}

} // namespace minesweeper
