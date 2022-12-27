#include "reverse_string.h"

#include <algorithm>

namespace reverse_string
{

auto reverse_string( std::string str ) -> std::string
{
    std::reverse( std::begin( str ), std::end( str ) );
    return str;
}

} // namespace reverse_string
