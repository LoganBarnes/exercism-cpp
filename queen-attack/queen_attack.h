#pragma

#include <stdexcept>
#include <utility>

namespace queen_attack {

using Pos = std::pair<int, int>;

auto operator-(Pos const& lhs, Pos const& rhs) noexcept -> Pos;

class chess_board {
public:
    chess_board(Pos white, Pos black);

    [[nodiscard]] auto white() const noexcept -> Pos const&;
    [[nodiscard]] auto black() const noexcept -> Pos const&;

    auto can_attack() const noexcept -> bool;

    static auto on_board(Pos const& pos) noexcept -> bool;

private:
    Pos white_;
    Pos black_;
};

} // namespace queen_attack
