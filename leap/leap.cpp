#include "leap.h"

namespace leap
{

auto is_leap_year( size_t year ) -> bool {
    auto div_by_4 = year % 4 == 0;
    auto div_by_100 = year % 100 == 0;
    auto div_by_400 = year % 400 == 0;
    return div_by_4 && (!div_by_100 || div_by_400);
}

} // namespace leap
