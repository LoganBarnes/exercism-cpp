#include "sum_of_multiples.h"

#include <numeric>
#include <unordered_set>

namespace sum_of_multiples
{

auto to( std::vector< int > const& item_values, int level ) -> int
{
    auto multiples = std::unordered_set< int >{ };
    for ( auto const& item_value : item_values )
    {
        for ( auto multiple = item_value; multiple < level; multiple += item_value )
        {
            multiples.insert( multiple );
        }
    }

    return std::accumulate( multiples.begin( ), multiples.end( ), 0 );
}

} // namespace sum_of_multiples
