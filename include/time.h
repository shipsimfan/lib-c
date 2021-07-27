#ifndef __TIME_H
#define __TIME_H

typedef __SIZE_TYPE__ size_t;
typedef long clock_t;
typedef long time_t;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

#include <time.h>

#define NULL ((void*)0)
#define CLOCKS_PER_SEC 1000000

char* asctime(const struct tm* timeptr);
char* asctime_r(const struct tm* timeptr, char* buf);
clock_t clock();
#define ctime(timep) asctime(localtime(timep))
#define ctime_r(timep, buf) asctime_r(localtime(timep), buf)
double difftime(time_t time1, time_t time2);
struct tm* gmtime(const time_t* timep);
struct tm* gmtime_r(const time_t* timep, struct tm* buf);
struct tm* localtime(const time_t* timep);
struct tm* localtime_r(const time_t* timep, struct tm* buf);
time_t mktime(struct tm* timeptr);
size_t strftime(char* str, size_t maxsize, const char* format, const struct tm* timeptr);
time_t time(time_t* timep);

#endif