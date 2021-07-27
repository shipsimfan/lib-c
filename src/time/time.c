#include <time.h>

#include <los/time.h>

time_t time(time_t* timep) {
    time_t ret = get_epoch_time();
    if (timep != NULL)
        *timep = ret;

    return ret;
}