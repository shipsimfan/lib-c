#include <time.h>

struct tm localtime_buffer;

struct tm* localtime(const time_t* timep) {
    return localtime_r(timep, &localtime_buffer);
}