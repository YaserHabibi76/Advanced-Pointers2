#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int encode_shift(char* line){

    int i;

    double result[26];
    int shift;

    for(shift = 0 ; shift<26; shift++){
        result[shift] = chi_sq(shift, line);
    }

    int shift_used = 0;

    for(i=1; i<26; i++){
        if (result[shift_used] > result[i]){
            shift_used = i;
        }
    }

    if(result[shift_used] >= 0.5 ){
        shift_used = 0;
        printf("The text isn't in english.\n");
    }

    return shift_used;
}