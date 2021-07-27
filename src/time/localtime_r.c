#include <time.h>

#include <los/time.h>

struct tm* localtime_r(const time_t* timep, struct tm* buf) {
    int64_t time_zone = get_time_zone();
    int64_t dst = time_zone & 1;
    time_zone = time_zone & ~1;

    time_t gmt_time = *timep + time_zone;
    gmtime_r(&gmt_time, buf);

    if (dst) {
        buf->tm_hour++;
        buf->tm_isdst = 1;
    }

    return buf;
}