#include <stdio.h>

#include "stdio.h"
#include <stdlib.h>

int ungetc(int c, FILE* stream) {
    UngetcNode* prev_node = NULL;
    UngetcNode* node = stream->ungetc;
    while(node != NULL) {
        prev_node = node;
        node = node->next;
    }

    UngetcNode* new_node = (UngetcNode*)malloc(sizeof(UngetcNode));
    new_node->next = NULL;
    new_node->c = c;

    if(prev_node == NULL)
        stream->ungetc = new_node;
    else
        prev_node->next = new_node;

    return c;
}