#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

#define DECLARE_FUNCTIONS( prefix, suffix )                                    \
    auto prefix##mon##suffix( ) const->greg::date;                             \
    auto prefix##tues##suffix( ) const->greg::date;                            \
    auto prefix##wednes##suffix( ) const->greg::date;                          \
    auto prefix##thurs##suffix( ) const->greg::date;                           \
    auto prefix##fri##suffix( ) const->greg::date;                             \
    auto prefix##satur##suffix( ) const->greg::date;                           \
    auto prefix##sun##suffix( ) const->greg::date

namespace meetup
{

namespace greg = boost::gregorian;

class scheduler
{
public:
    explicit scheduler(
        greg::months_of_year const& month,
        unsigned short              year
    );

    DECLARE_FUNCTIONS(, teenth );
    DECLARE_FUNCTIONS( first_, day );
    DECLARE_FUNCTIONS( second_, day );
    DECLARE_FUNCTIONS( third_, day );
    DECLARE_FUNCTIONS( fourth_, day );
    DECLARE_FUNCTIONS( last_, day );

private:
    greg::months_of_year month_;
    unsigned short       year_;
};

} // namespace meetup
