#pragma once

#include <stdexcept>
#include <utility>

namespace queen_attack {

using namespace std;

using Pos = pair<int, int>;

inline auto on_board(Pos const& p) {
    return 0 <= p.first && p.first < 8 && 0 <= p.second && p.second < 8;
}

struct chess_board {
    chess_board(Pos white, Pos black) : w_(white), b_(black) {
        if (w_ == b_)                       { throw domain_error("Same pos"); }
        if (!on_board(w_) || !on_board(b_)) { throw domain_error("Off board"); }
    }

    auto white() const -> Pos const& { return w_; }
    auto black() const -> Pos const& { return b_; }

    auto can_attack() const {
        auto const d = make_pair(w_.first - b_.first, w_.second - b_.second);
        return d.first * d.second == 0 || abs(d.first) == abs(d.second);
    }

private:
    Pos w_, b_;
};

} // namespace queen_attack
