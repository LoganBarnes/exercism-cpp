#include "queen_attack.h"

namespace queen_attack {

auto operator-(Pos const& lhs, Pos const& rhs) noexcept -> Pos {
    return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

chess_board::chess_board(Pos white, Pos black) : white_(white), black_(black) {
    if (!chess_board::on_board(black_)) {
        throw std::domain_error("Black piece is not on the board");
    }
    if (!chess_board::on_board(white_)) {
        throw std::domain_error("White piece is not on the board");
    }
    if (white_ == black_) {
        throw std::invalid_argument("White and black pieces are co-located");
    }
}

auto chess_board::white() const noexcept -> Pos const& {
    return white_;
}

auto chess_board::black() const noexcept -> Pos const& {
    return black_;
}

auto chess_board::can_attack() const noexcept -> bool {
    auto const diff           = white_ - black_;
    auto const col_row_attack = diff.first * diff.second == 0;
    auto const diag_attack    = std::abs(diff.first) == std::abs(diff.second);
    return col_row_attack || diag_attack;
}

auto chess_board::on_board(Pos const& pos) noexcept -> bool {
    auto on_board_axis = [](auto p) { return 0 <= p && p < 8; };
    return on_board_axis(pos.first) && on_board_axis(pos.second);
}

} // namespace queen_attack
