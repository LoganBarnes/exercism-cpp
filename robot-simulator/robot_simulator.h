#pragma once

#include <string>
#include <utility>

namespace robot_simulator {

using Point = std::pair<int, int>;

enum class Bearing : uint8_t {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

class Robot {
public:
    explicit Robot(
        Point position = {0, 0}, Bearing bearing = Bearing::NORTH
    ) noexcept;

    [[nodiscard]] auto get_position() const noexcept -> Point const&;
    [[nodiscard]] auto get_bearing() const noexcept -> Bearing;

    auto advance() noexcept -> void;
    auto turn_right() noexcept -> void;
    auto turn_left() noexcept -> void;

    /// \throws std::invalid_argument if the string contains a character
    ///                               that is not 'A', 'L', or 'R'.
    auto execute_sequence(std::string const& sequence) -> void;

private:
    Point   position_;
    Bearing bearing_;
};

} // namespace robot_simulator
