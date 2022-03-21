#include <losstd.h>

#include <stdio.h>

void get_current_stdio(StandardIO* stdio) {
    stdio->stdout_type = stdout->type;
    stdio->stdout_desc = stdout->descriptor;
    stdio->stderr_type = stderr->type;
    stdio->stderr_desc = stderr->descriptor;
    stdio->stdin_type = stdin->type;
    stdio->stdin_desc = stdin->descriptor;
}