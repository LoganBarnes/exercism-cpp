#include "gigasecond.h"

namespace gigasecond {

auto advance(boost::posix_time::ptime time) -> boost::posix_time::ptime {
    return time + boost::posix_time::seconds(1'000'000'000);
}

}  // namespace gigasecond
