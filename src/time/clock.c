#include <time.h>

#include <los/time.h>

clock_t clock() { return get_process_time(); }