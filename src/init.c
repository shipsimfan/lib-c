#include <stddef.h>
#include <stdint.h>

char** environ;

void initialize_standard_library(const char** envp) { environ = (char**)envp; }
