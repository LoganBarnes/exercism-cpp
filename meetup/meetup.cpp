#include "meetup.h"

namespace greg = boost::gregorian;

#define DEFINE_DAY_FUNCTION( prefix, day, suffix, weekday_func, day_number, day_name, date_modifier )                  \
    auto scheduler::prefix##day##suffix( ) const->greg::date                                                           \
    {                                                                                                                  \
        return greg::weekday_func(                                                                                     \
            greg::date{ year_, month_, day_number } date_modifier,                                                     \
            greg::greg_weekday{ greg::day_name }                                                                       \
        );                                                                                                             \
    }

#define DEFINE_DAY_FUNCTIONS( prefix, suffix, weekday_func, day_number, date_modifier )                                \
    DEFINE_DAY_FUNCTION( prefix, mon, suffix, weekday_func, day_number, Monday, date_modifier )                        \
    DEFINE_DAY_FUNCTION( prefix, tues, suffix, weekday_func, day_number, Tuesday, date_modifier )                      \
    DEFINE_DAY_FUNCTION( prefix, wednes, suffix, weekday_func, day_number, Wednesday, date_modifier )                  \
    DEFINE_DAY_FUNCTION( prefix, thurs, suffix, weekday_func, day_number, Thursday, date_modifier )                    \
    DEFINE_DAY_FUNCTION( prefix, fri, suffix, weekday_func, day_number, Friday, date_modifier )                        \
    DEFINE_DAY_FUNCTION( prefix, satur, suffix, weekday_func, day_number, Saturday, date_modifier )                    \
    DEFINE_DAY_FUNCTION( prefix, sun, suffix, weekday_func, day_number, Sunday, date_modifier )

namespace meetup
{

scheduler::scheduler( greg::months_of_year const& month, unsigned short year )
    : month_{ month }
    , year_{ year }
{
}

DEFINE_DAY_FUNCTIONS(, teenth, next_weekday, 13, )
DEFINE_DAY_FUNCTIONS( first_, day, next_weekday, 1, )
DEFINE_DAY_FUNCTIONS( second_, day, next_weekday, 8, )
DEFINE_DAY_FUNCTIONS( third_, day, next_weekday, 15, )
DEFINE_DAY_FUNCTIONS( fourth_, day, next_weekday, 22, )
DEFINE_DAY_FUNCTIONS( last_, day, previous_weekday, 1, .end_of_month( ) )

} // namespace meetup
