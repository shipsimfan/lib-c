#include <stdlib.h>

#include <stdint.h>
#include <string.h>

int setenv(const char* name, const char* value, int overwrite) {
    // Create variable
    int name_length = strlen(name);
    int value_length = strlen(value);
    char* variable = (char*)malloc(name_length + value_length + 2);
    int idx = 0;
    for (int i = 0; i < name_length; i++, idx++)
        variable[idx] = name[i];
    variable[idx++] = '=';
    for (int i = 0; i < value_length; i++, idx++)
        variable[idx] = value[i];
    variable[idx] = 0;

    // Search for environment variable
    char** envp = environ;
    int environ_length = 0;
    while (*envp) {
        char* ptr = *envp;
        for (int j = 0; *ptr; ptr++, j++) {
            if (*ptr == '=') {
                if (name[j] == 0) {
                    if (overwrite != 0) {
                        free(*envp);
                        *envp = variable;
                    } else
                        free(variable);

                    return 0;
                }
                break;
            }

            if (*ptr != name[j])
                break;
        }
        environ_length++;
        envp++;
    }

    // Allocate new environ
    char** new_environ = (char**)malloc(sizeof(char*) * (environ_length + 2));

    // Copy old variables
    for (int i = 0; i < environ_length; i++)
        new_environ[i] = environ[i];

    free(environ);

    // Insert new variable
    new_environ[environ_length] = variable;
    new_environ[environ_length + 1] = NULL;

    environ_length = environ_length + 1;
    environ = new_environ;

    return 0;
}