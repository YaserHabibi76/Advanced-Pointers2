#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int to_decode(int shift){
    int shift_decode = 0;
    shift_decode -= shift;
    return shift_decode;
}