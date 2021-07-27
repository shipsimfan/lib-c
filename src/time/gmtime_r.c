#include <time.h>

#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

#define DAYS_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366

const long month_length[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(long year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            return 0;
        }
        return 1;
    }

    return 0;
}

long day_of_week(long month, long day, long year) {
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + "-bed=pen+mad."[month] + day) % 7;
}

struct tm* gmtime_r(const time_t* timep, struct tm* buf) {
    long day = *timep / SECONDS_IN_DAY;
    long seconds = *timep % SECONDS_IN_DAY;

    // Calculate time
    long hour = seconds / SECONDS_IN_HOUR;
    seconds = seconds % SECONDS_IN_HOUR;
    long minute = seconds / SECONDS_IN_MINUTE;
    seconds = seconds % SECONDS_IN_MINUTE;

    // Calculate date
    long year = 1970;
    while (1) {
        int leap_year = is_leap_year(year);

        if (leap_year) {
            if (day >= DAYS_IN_LEAP_YEAR) {
                year++;
                day -= DAYS_IN_LEAP_YEAR;
            } else
                break;
        } else {
            if (day >= DAYS_IN_YEAR) {
                year++;
                day -= DAYS_IN_YEAR;
            } else
                break;
        }
    }

    long year_day = day;

    long month = 0;
    while (1) {
        if (month == 1) {
            if (is_leap_year(year)) {
                if (day >= 29) {
                    month++;
                    day -= 29;
                } else
                    break;
            } else {
                if (day >= 28) {
                    month++;
                    day -= 28;
                } else
                    break;
            }
        } else {
            if (day >= month_length[month]) {
                day -= month_length[month];
                month++;
            } else
                break;
        }
    }

    day++;

    long weekday = day_of_week((month + 1), day, year);

    buf->tm_sec = seconds;
    buf->tm_min = minute;
    buf->tm_hour = hour;
    buf->tm_mday = day;
    buf->tm_mon = month;
    buf->tm_year = year - 1900;
    buf->tm_wday = weekday;
    buf->tm_yday = year_day;
    buf->tm_isdst = 0;

    return buf;
}