#pragma once

#include <stdexcept>
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
    explicit Robot(Point position = {0, 0}, Bearing bearing = Bearing::NORTH)
        : position_(position)
        , bearing_(bearing) {}

    auto get_position() const -> Point const& { return position_; }

    auto get_bearing() const -> Bearing { return bearing_; }

    auto advance() -> void {
        switch (bearing_) {
            case Bearing::NORTH:
                position_.second += 1;
                break;
            case Bearing::EAST:
                position_.first += 1;
                break;
            case Bearing::SOUTH:
                position_.second -= 1;
                break;
            case Bearing::WEST:
                position_.first -= 1;
                break;
        }
    }

    auto turn_right() -> void {
        auto bearing = std::underlying_type_t<Bearing>(bearing_);
        bearing_     = static_cast<Bearing>((bearing + 1) % 4);
    }

    auto turn_left() -> void {
        auto bearing = std::underlying_type_t<Bearing>(bearing_);
        bearing_     = static_cast<Bearing>((bearing + 3) % 4);
    }

    auto execute_sequence(std::string const& sequence) -> void {
        for (auto c : sequence) {
            switch (c) {
                case 'A':
                    advance();
                    break;
                case 'R':
                    turn_right();
                    break;
                case 'L':
                    turn_left();
                    break;
                default:
                    throw std::invalid_argument(
                        "Unexpected character: '" + std::string{c} + "'"
                    );
            }
        }
    }

private:
    Point   position_;
    Bearing bearing_;
};

} // namespace robot_simulator
