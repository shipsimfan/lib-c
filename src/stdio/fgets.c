#include <stdio.h>

char* fgets(char* str, int n, FILE* stream) {
    int i;
    for(i = 0; i < n - 1; i++) {
        int val = fgetc(stream);

        if(val < 0) {
            if(i == 0 || !feof(stream))
                return NULL;
            
            str[i] = 0;
            return str;
        }

        str[i] = val;
        
        if(val == '\n') {
            i++;
            break;
        }
    }

    str[i] = 0;
    return str;
}