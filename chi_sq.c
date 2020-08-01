#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

double chi_sq(int shift, char*line){

    int i, j;
    int letCount;
    int *eachCount;

    letCount = letter_count(line);
    eachCount = frequency_table(line);

    double ef[26] = EF;
    double s;
    double text_freq[26];

    for(i=0; i<26; i++){
        text_freq[i] = eachCount[i];
    }


    int p;

    int shifted;
    
    s=0;

    for(j=0; j<26; j++){
        p = j+97;
        shifted = encode(p, shift);
        s += ((((letCount*ef[j]) - text_freq[shifted]) * ((letCount*ef[j]) - text_freq[shifted]))/(letCount*letCount*ef[j]));
    }

    return s;
}