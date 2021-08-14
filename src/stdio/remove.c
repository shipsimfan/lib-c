#include <stdlib.h>

#include <los/error.h>
#include <los/filesystem.h>

int remove(const char* filename) {
    isize status = remove_file(filename);
    if (status == EISDIR) {
        if (remove_directory(filename) < 0)
            return -1;

        return 0;
    } else if (status < 0)
        return -1;

    return 0;
}