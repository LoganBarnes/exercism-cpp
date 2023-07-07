#include "meetup.h"

namespace meetup
{

scheduler::scheduler( greg::months_of_year const& month, unsigned short year )
    : month_{ month }
    , year_{ year }
{
}

auto scheduler::monteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::tuesteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::wednesteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::thursteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::friteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::saturteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::sunteenth( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 13 },
        greg::greg_weekday{ greg::Sunday }
    );
}

auto scheduler::first_monday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::first_tuesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::first_wednesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::first_thursday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::first_friday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::first_saturday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::first_sunday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 1 },
        greg::greg_weekday{ greg::Sunday }
    );
}

auto scheduler::second_monday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::second_tuesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::second_wednesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::second_thursday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::second_friday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::second_saturday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::second_sunday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 8 },
        greg::greg_weekday{ greg::Sunday }
    );
}

auto scheduler::third_monday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::third_tuesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::third_wednesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::third_thursday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::third_friday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::third_saturday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::third_sunday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 15 },
        greg::greg_weekday{ greg::Sunday }
    );
}

auto scheduler::fourth_monday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::fourth_tuesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::fourth_wednesday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::fourth_thursday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::fourth_friday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::fourth_saturday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::fourth_sunday( ) const -> greg::date
{
    return greg::next_weekday(
        greg::date{ year_, month_, 22 },
        greg::greg_weekday{ greg::Sunday }
    );
}

auto scheduler::last_monday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Monday }
    );
}

auto scheduler::last_tuesday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Tuesday }
    );
}

auto scheduler::last_wednesday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Wednesday }
    );
}

auto scheduler::last_thursday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Thursday }
    );
}

auto scheduler::last_friday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Friday }
    );
}

auto scheduler::last_saturday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Saturday }
    );
}

auto scheduler::last_sunday( ) const -> greg::date
{
    return greg::previous_weekday(
        greg::date{ year_, month_, 1 }.end_of_month( ),
        greg::greg_weekday{ greg::Sunday }
    );
}

} // namespace meetup
