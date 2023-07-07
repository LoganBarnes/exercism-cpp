#include "prime_factors.h"

namespace prime_factors
{

auto of( int number ) -> std::vector< int >
{
    // github copilot for the win!
    auto factors = std::vector< int >{ };
    for ( auto divisor = 2; number > 1; ++divisor )
    {
        for ( ; number % divisor == 0; number /= divisor )
        {
            factors.push_back( divisor );
        }
    }
    return factors;
}

} // namespace prime_factors
