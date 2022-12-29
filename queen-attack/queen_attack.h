#pragma once

#include <stdexcept>
#include <utility>

namespace queen_attack {

using Pos = std::pair<int, int>;

inline auto valid(Pos const& pos) {
    return 0 <= pos.first && pos.first < 8 && 0 <= pos.second && pos.second < 8;
}

inline auto operator-(Pos const& lhs, Pos const& rhs) {
    return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}

struct chess_board {
    chess_board(Pos white, Pos black) : white_(white), black_(black) {
        if (!valid(white_) || !valid(black_)) { throw std::domain_error(""); }
    }

    auto white() const -> Pos const& { return white_; }
    auto black() const -> Pos const& { return black_; }

    auto can_attack() const {
        auto diff = white_ - black_;
        return diff.first * diff.second == 0
            || std::abs(diff.first) == std::abs(diff.second);
    }

private:
    Pos white_, black_;
};

} // namespace queen_attack
