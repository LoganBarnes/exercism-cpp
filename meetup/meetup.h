#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace bg = boost::gregorian;

#define DEFINE_DAY_FUNCTION( prefix, day, suffix, func, day_num, day_name, date_mod )                                  \
    auto prefix##day##suffix( ) const->bg::date {                                                                      \
        return bg::func( bg::date{ year_, month_, day_num } date_mod, bg::greg_weekday{ bg::day_name } );              \
    }

#define DEFINE_DAY_FUNCTIONS( prefix, suffix, func, day_num, date_mod )                                                \
    DEFINE_DAY_FUNCTION( prefix, mon, suffix, func, day_num, Monday, date_mod )                                        \
    DEFINE_DAY_FUNCTION( prefix, tues, suffix, func, day_num, Tuesday, date_mod )                                      \
    DEFINE_DAY_FUNCTION( prefix, wednes, suffix, func, day_num, Wednesday, date_mod )                                  \
    DEFINE_DAY_FUNCTION( prefix, thurs, suffix, func, day_num, Thursday, date_mod )                                    \
    DEFINE_DAY_FUNCTION( prefix, fri, suffix, func, day_num, Friday, date_mod )                                        \
    DEFINE_DAY_FUNCTION( prefix, satur, suffix, func, day_num, Saturday, date_mod )                                    \
    DEFINE_DAY_FUNCTION( prefix, sun, suffix, func, day_num, Sunday, date_mod )

namespace meetup
{

class scheduler
{
public:
    explicit scheduler( bg::months_of_year const& month, unsigned short year )
        : month_{ month } , year_{ year } {}

    DEFINE_DAY_FUNCTIONS( ,        teenth, next_weekday,    13,                  )
    DEFINE_DAY_FUNCTIONS( first_,  day,    next_weekday,     1,                  )
    DEFINE_DAY_FUNCTIONS( second_, day,    next_weekday,     8,                  )
    DEFINE_DAY_FUNCTIONS( third_,  day,    next_weekday,    15,                  )
    DEFINE_DAY_FUNCTIONS( fourth_, day,    next_weekday,    22,                  )
    DEFINE_DAY_FUNCTIONS( last_,   day,    previous_weekday, 1, .end_of_month( ) )

private:
    bg::months_of_year month_;
    unsigned short     year_;
};

} // namespace meetup
