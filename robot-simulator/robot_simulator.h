#pragma once

#include <string>
#include <utility>

namespace robot_simulator {

using Point = std::pair<int, int>;

enum Bearing { NORTH, EAST, SOUTH, WEST };

struct Robot {
    Robot(Point position = {0, 0}, Bearing bearing = Bearing::NORTH)
        : pos_(position), bearing_(bearing) {}

    auto get_position() const -> Point const& { return pos_; }
    auto get_bearing() const -> Bearing { return bearing_; }

    auto advance() -> void {
        switch (bearing_) {
            case Bearing::NORTH: ++pos_.second; break;
            case Bearing::EAST:  ++pos_.first;  break;
            case Bearing::SOUTH: --pos_.second; break;
            case Bearing::WEST:  --pos_.first;  break;
        }
    }
    auto turn_right() -> void { bearing_ = Bearing((bearing_ + 1) % 4); }
    auto turn_left() -> void { bearing_ = Bearing((bearing_ + 3) % 4);}

    auto execute_sequence(std::string const& sequence) -> void {
        for (auto c : sequence) {
            switch (c) {
                case 'A': advance();    break;
                case 'R': turn_right(); break;
                case 'L': turn_left();  break;
            }
        }
    }

private:
    Point pos_; Bearing bearing_;
};

} // namespace robot_simulator
