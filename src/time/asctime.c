#include <time.h>

char* asctime_buf = "Www Mmm dd hh:mm:ss yyyy\n";

char* asctime(const struct tm* timeptr) { return asctime_r(timeptr, asctime_buf); }