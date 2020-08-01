#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(){

    char*line;
    int i;
    int charCount = 0;
    int *eachCount;
    int letCount;

    printf("Your text here: ");
    
    line = read(stdin);

    for(i=0; line[i]!='\0'; i++){
        charCount++;
    }
    
    letCount = letter_count(line);

    printf("Number of letters in the text: %d\n", letCount);
    printf("Total number of characters in the text: %d\n", charCount);

    eachCount = frequency_table(line);

    printf("letter  letCount\n");
    
    for(i=0; i<26; i++){

        char letter;
        letter = (65+i);
        printf("%c        %d\n",letter, eachCount[i]);

    }
    
    free(eachCount);
    free(line);

    return 0;
}