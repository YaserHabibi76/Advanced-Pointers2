#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

char *decoder(char* line, int shift){

    int i, j;
    char ch;

    for(i=0; line[i]!='\0'; i++){
        ch = line[i];
        j = ch;
        if(ch >= 'a' && ch <='z'){
            ch += shift;
            if( ch >'z'){
                ch = ch - 'z' + 'a' - 1;
            }else if( ch < 'a'){
                ch = ch + 'z' - 'a' +1;
            }   
            line[i] = ch;
        }else if( ch >= 'A' && ch <= 'Z'){
            ch += shift;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }else if(ch < 'A'){
                ch = ch + 'Z' - 'A' +1;
            }
            line[i] = ch;
        }else if (ch == '\n'){
            line[i] = ch;
        }
    }

    return line;
}