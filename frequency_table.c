#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int *frequency_table(char *array){
    int *count;
    count = malloc(sizeof(int) * 26);
    int i, j, k;
    int letter;

    for(i=0; i<26; i++){
        count[i] = 0;
    }

    for(j=0; array[j]!='\0'; j++){  
        letter = array[j];
        
        for(i=0; i<26; i++){
            
            k=0; 
            if(letter == (65+i)){
                k++;
            }else if(letter == (97+i)){
                k++;
            }
            
            count[i] += k;     
        }
    }
    return count;
}