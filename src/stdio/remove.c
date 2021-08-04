#include <stdlib.h>

#include <los/filesystem.h>
#include <los/error.h>

int remove(const char* filename) {
    int64_t status = remove_file(filename);
    if(status == EISDIR) {
        if(remove_directory(filename) < 0)
            return -1;
        
        return 0;
    } else if(status < 0)
        return -1;

    return 0;
}