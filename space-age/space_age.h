#pragma once

#include <chrono>
#include <cstdint>

namespace space_age
{

using year = std::chrono::duration< double, std::ratio< 31557600 > >;

class space_age
{
public:
    explicit space_age( uint64_t age_seconds ): age_( std::chrono::seconds( age_seconds ) ) {}

    [[nodiscard]] auto seconds( ) const { return std::chrono::duration_cast< std::chrono::seconds >( age_ ).count( ); }
    [[nodiscard]] auto on_earth( ) const { return std::chrono::duration_cast< year >( age_ ).count( ); }
    [[nodiscard]] auto on_mercury( ) const { return this->on_earth( ) / 0.2408467; }
    [[nodiscard]] auto on_venus( ) const { return this->on_earth( ) / 0.61519726; }
    [[nodiscard]] auto on_mars( ) const { return this->on_earth( ) / 1.8808158; }
    [[nodiscard]] auto on_jupiter( ) const { return this->on_earth( ) / 11.862615; }
    [[nodiscard]] auto on_saturn( ) const { return this->on_earth( ) / 29.447498; }
    [[nodiscard]] auto on_uranus( ) const { return this->on_earth( ) / 84.016846; }
    [[nodiscard]] auto on_neptune( ) const { return this->on_earth( ) / 164.79132; }

private:
    std::chrono::milliseconds age_; // this can be any std::chrono::duration
};

} // namespace space_age
