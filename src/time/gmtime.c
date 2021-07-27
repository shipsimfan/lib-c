#include <time.h>

struct tm gmttime_buffer;

struct tm* gmtime(const time_t* timep) {
    return gmtime_r(timep, &gmttime_buffer);
}