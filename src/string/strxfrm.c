#include <string.h>

size_t strxfrm(char* dest, const char* src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    strncpy(dest, src, n);

    if (n > dest_len && n > src_len)
        return n;
    else if (dest_len > src_len)
        return dest_len;
    else
        return src_len;
}