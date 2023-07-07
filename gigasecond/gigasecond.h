#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond {

auto advance(boost::posix_time::ptime time) -> boost::posix_time::ptime;

}  // namespace gigasecond
