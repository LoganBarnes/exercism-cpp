#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot(Point position, Bearing bearing) noexcept
    : position_(position)
    , bearing_(bearing) {}

auto Robot::get_position() const noexcept -> Point const& {
    return position_;
}

auto Robot::get_bearing() const noexcept -> Bearing {
    return bearing_;
}

auto Robot::advance() noexcept -> void {
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

auto Robot::turn_right() noexcept -> void {
    auto bearing = std::underlying_type_t<Bearing>(bearing_);
    bearing_     = static_cast<Bearing>((bearing + 1) % 4);
}

auto Robot::turn_left() noexcept -> void {
    auto bearing = std::underlying_type_t<Bearing>(bearing_);
    bearing_     = static_cast<Bearing>((bearing + 3) % 4);
}

auto Robot::execute_sequence(std::string const& sequence) -> void {
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

} // namespace robot_simulator
