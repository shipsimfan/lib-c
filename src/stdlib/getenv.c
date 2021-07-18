#include <stdlib.h>

char* getenv(const char* name) {
    char** envp = environ;
    while (*envp) {
        char* ptr = *envp;
        for (int j = 0; *ptr; ptr++, j++) {
            if (*ptr == '=') {
                if (name[j] == 0)
                    return *envp;
                break;
            }

            if (*ptr != name[j])
                break;
        }
        envp++;
    }

    return NULL;
}