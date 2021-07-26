#include <errno.h>

_Thread_local int __errno;

int* __errno_location() { return &__errno; }