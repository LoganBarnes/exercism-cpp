#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

#define DECLARE_DAY_FUNCTION( prefix, day, suffix )                            \
    auto prefix##day##suffix( ) const->boost::gregorian::date

#define DECLARE_DAY_FUNCTIONS( prefix, suffix )                                \
    DECLARE_DAY_FUNCTION( prefix, mon, suffix );                               \
    DECLARE_DAY_FUNCTION( prefix, tues, suffix );                              \
    DECLARE_DAY_FUNCTION( prefix, wednes, suffix );                            \
    DECLARE_DAY_FUNCTION( prefix, thurs, suffix );                             \
    DECLARE_DAY_FUNCTION( prefix, fri, suffix );                               \
    DECLARE_DAY_FUNCTION( prefix, satur, suffix );                             \
    DECLARE_DAY_FUNCTION( prefix, sun, suffix )

namespace meetup
{

class scheduler
{
public:
    explicit scheduler(
        boost::gregorian::months_of_year const& month,
        unsigned short                          year
    );

    DECLARE_DAY_FUNCTIONS(, teenth );
    DECLARE_DAY_FUNCTIONS( first_, day );
    DECLARE_DAY_FUNCTIONS( second_, day );
    DECLARE_DAY_FUNCTIONS( third_, day );
    DECLARE_DAY_FUNCTIONS( fourth_, day );
    DECLARE_DAY_FUNCTIONS( last_, day );

private:
    boost::gregorian::months_of_year month_;
    unsigned short                   year_;
};

} // namespace meetup
