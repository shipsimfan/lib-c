#ifndef __ERRNO_H
#define __ERRNO_H

#include <los/error.h>

int* __errno_location();
#define errno (*__errno_location())

#endif