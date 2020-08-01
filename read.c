#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

char *read(FILE* input){
    int max_len = 100;
    int cur_len = 0;

    char *ptr = malloc (max_len);
    cur_len = max_len;

    if (ptr != NULL){
        int c = EOF;
        int i = 0;
        while (( c = getchar() ) != EOF){
            ptr[i++] = (char) c;
            
            if( i == cur_len){
                cur_len = i+max_len;
                ptr = realloc(ptr, cur_len);
            }
        }
        ptr[i] = '\0';
    }

return ptr;
}