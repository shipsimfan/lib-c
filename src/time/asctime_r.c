#include <time.h>

const char days[7][3] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char months[12][3] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

char* asctime_r(const struct tm* timeptr, char* buf) {
    char* ret = buf;

    for (int i = 0; i < 3; i++, buf++)
        *buf = days[timeptr->tm_wday][i];

    *buf = ' ';
    buf++;

    for (int i = 0; i < 3; i++, buf++)
        *buf = months[timeptr->tm_mon][i];

    *buf = ' ';
    buf++;

    *buf = (timeptr->tm_mday / 10) + '0';
    buf++;
    *buf = (timeptr->tm_mday % 10) + '0';
    buf++;

    *buf = ' ';
    buf++;

    *buf = (timeptr->tm_hour / 10) + '0';
    buf++;
    *buf = (timeptr->tm_hour % 10) + '0';
    buf++;

    *buf = ':';
    buf++;

    *buf = (timeptr->tm_min / 10) + '0';
    buf++;
    *buf = (timeptr->tm_min % 10) + '0';
    buf++;

    *buf = ':';
    buf++;

    *buf = (timeptr->tm_sec / 10) + '0';
    buf++;
    *buf = (timeptr->tm_sec % 10) + '0';
    buf++;

    *buf = ' ';
    buf++;

    int year = timeptr->tm_year + 1900;
    for (int i = 0; i < 4; i++) {
        buf[3 - i] = (year % 10) + '0';
        year /= 10;
    }

    buf += 4;

    *buf = '\n';
    buf++;
    *buf = 0;

    return ret;
}