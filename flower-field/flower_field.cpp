#include "flower_field.h"

namespace flower_field {

using Counts1d = std::vector<size_t>;
using Counts2d = std::vector<Counts1d>;

template <typename Callback>
auto iterate(size_t const row_count, size_t const col_count, Callback const& callback) {
    for (auto row_i = 0U; row_i < row_count; ++row_i) {
        for (auto col_i = 0U; col_i < col_count; ++col_i) {
            callback(row_i, col_i);
        }
    }
}

template <typename Callback>
auto safely_count_1d(size_t const row_count, size_t const col_count, Callback const& add) {
    auto counts = Counts2d(row_count, Counts1d(col_count, 0U));
    auto count  = [&counts, col_count, &add](size_t const row_i, size_t const col_i) {
        if (col_i > 0U) {
            counts[row_i][col_i] += add(row_i, col_i - 1U);
        }
        if (col_i + 1U < col_count) {
            counts[row_i][col_i] += add(row_i, col_i + 1U);
        }
    };

    iterate(row_count, col_count, count);

    return counts;
}

struct IfFlower {
    Field const& field;

    auto operator()(size_t const row_i, size_t const col_i) const -> size_t {
        return field[row_i][col_i] == '*' ? 1U : 0U;
    }
};

struct IfFlowerAndCount {
    Field const&    field;
    Counts2d const& counts;
    IfFlower        if_flower = {field};

    auto operator()(size_t const col_i, size_t const row_i) const -> size_t {
        return if_flower(row_i, col_i) + counts[row_i][col_i];
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

    auto col_counts = safely_count_1d(row_count, col_count, IfFlower{field});

    auto row_counts = safely_count_1d(col_count, row_count, IfFlowerAndCount{field, col_counts});

    auto annotated = field;

    constexpr auto zero = static_cast<size_t>('0');

    iterate(
        row_count,
        col_count,
        [&annotated, &col_counts, &row_counts](size_t const row_i, size_t const col_i) {
            auto const count = col_counts[row_i][col_i] + row_counts[col_i][row_i];
            if (annotated[row_i][col_i] == ' ' && count != 0) {
                annotated[row_i][col_i] = static_cast<char>(zero + count);
            }
        }
    );

    return annotated;
}

} // namespace flower_field
