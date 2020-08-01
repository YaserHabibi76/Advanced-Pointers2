#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int encode(int letter, int shift){
    int encoded;
    int i, j;
    char ch;

    ch = letter;
    j = ch;
    if(ch >= 'a' && ch <='z'){
        if( (j+=shift) >'z'){
            ch = ch - 'z' + 'a' - 1;
        }
        ch += shift;                
        letter = ch;

    }else if( ch >= 'A' && ch <= 'Z'){
        ch += shift;
        if(ch > 'Z'){
            ch = ch - 'Z' + 'A' - 1;
        }
        letter = ch;
    }

    encoded = letter;

    if(encoded > 64 && encoded < 91){
        encoded -= 65;
    }else if( encoded >96 && encoded <123){
        encoded -= 97;
    }

    return encoded; 
}