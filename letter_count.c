#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int letter_count( char* array){
    
    int count = 0;
    int i;

    for(i=0; array[i]!='\0'; i++){
        if( array[i]>64 && array[i]<91){
            count++;
        }else if( array[i]>96 && array[i]<123){
            count++;
        }
    }

    return count;
}