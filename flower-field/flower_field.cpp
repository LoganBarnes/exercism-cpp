#include "flower_field.h"

namespace flower_field {

auto annotate(Field const& field) -> Field {
    auto const row_count = field.size();
    if (0 == row_count) {
        return field;
    }

    auto const column_count = field.front().size();
    if (0 == column_count) {
        return field;
    }

    auto col_counts = std::vector<
        std::vector<size_t>>(row_count, std::vector<size_t>(column_count, 0U));

    for (auto row_i = 0U; row_i < row_count; ++row_i) {
        for (auto col_i = 0U; col_i < column_count; ++col_i) {
            if (col_i > 0U && field[row_i][col_i - 1U] == '*') {
                ++col_counts[row_i][col_i];
            }
            if (col_i + 1U < column_count && field[row_i][col_i + 1U] == '*') {
                ++col_counts[row_i][col_i];
            }
        }
    }

    auto counts = std::vector<
        std::vector<size_t>>(row_count, std::vector<size_t>(column_count, 0U));

    for (auto col_i = 0U; col_i < column_count; ++col_i) {
        for (auto row_i = 0U; row_i < row_count; ++row_i) {
            counts[row_i][col_i] = col_counts[row_i][col_i];
            if (row_i > 0U) {
                counts[row_i][col_i] += col_counts[row_i - 1U][col_i];
                if (field[row_i - 1U][col_i] == '*') {
                    ++counts[row_i][col_i];
                }
            }
            if (row_i + 1U < row_count) {
                counts[row_i][col_i] += col_counts[row_i + 1U][col_i];
                if (field[row_i + 1U][col_i] == '*') {
                    ++counts[row_i][col_i];
                }
            }
        }
    }

    auto annotated = field;

    constexpr auto zero = static_cast<size_t>('0');

    for (auto row_i = 0U; row_i < row_count; ++row_i) {
        for (auto col_i = 0U; col_i < column_count; ++col_i) {
            if (annotated[row_i][col_i] == ' ' && counts[row_i][col_i] != 0) {
                annotated[row_i][col_i]
                    = static_cast<char>(zero + counts[row_i][col_i]);
            }
        }
    }

    return annotated;
}

} // namespace flower_field
