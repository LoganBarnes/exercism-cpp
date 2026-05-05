#include "flower_field.h"

namespace flower_field {

using Counts1d = std::vector<uint8_t>;
using Counts2d = std::vector<Counts1d>;

template <bool Adjacent, typename Output, typename Callback>
auto iterate(Output& output, size_t const rows, size_t const cols, Callback const& callback) {
    for (auto row_i = 0U; row_i < rows; ++row_i) {
        for (auto col_i = 0U; col_i < cols; ++col_i) {
            if constexpr (Adjacent) {
                if (col_i > 0U) {
                    output[row_i][col_i] += callback(row_i, col_i - 1U);
                }
                if (col_i + 1U < cols) {
                    output[row_i][col_i] += callback(row_i, col_i + 1U);
                }
            } else {
                output[row_i][col_i] = callback(row_i, col_i);
            }
        }
    }
}

struct IfFlower {
    Field const& field;

    auto operator()(size_t const row, size_t const col) const -> size_t {
        return field[row][col] == '*' ? 1U : 0U;
    }
};

struct IfFlowerAndCount {
    Field const&    field;
    Counts2d const& counts;
    IfFlower        if_flower = {field};

    auto operator()(size_t const col, size_t const row) const -> size_t {
        return if_flower(row, col) + counts[row][col];
    }
};

struct CountIfSpace {
    Field const&    field;
    Counts2d const& col_counts;
    Counts2d const& row_counts;

    auto operator()(size_t const row, size_t const col) const -> char {
        constexpr auto zero = static_cast<uint8_t>('0');

        auto const count = col_counts[row][col] + row_counts[col][row];
        auto const ch    = field[row][col];
        if ((' ' == ch) && (0U != count)) {
            return static_cast<char>(zero + count);
        }
        return ch;
    }
};

auto annotate(Field const& field) -> Field {
    auto const row_count = field.size();
    if (0 == row_count) {
        return field;
    }

    auto const col_count = field.front().size();
    if (0 == col_count) {
        return field;
    }

    auto col_counts = Counts2d{row_count, Counts1d(col_count, 0U)};
    iterate<true>(col_counts, row_count, col_count, IfFlower{field});

    auto row_counts = Counts2d{col_count, Counts1d(row_count, 0U)};
    iterate<true>(row_counts, col_count, row_count, IfFlowerAndCount{field, col_counts});

    auto annotated = field;
    iterate<false>(annotated, row_count, col_count, CountIfSpace{field, col_counts, row_counts});

    return annotated;
}

} // namespace flower_field
