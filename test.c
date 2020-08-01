#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"


int main(int argc, char *argv[]){

    char*line;
    int i, j, s;
    int shift;
    char *decoded;

    char fileNameIn[100];
    char fileNameOut[100];

    int stdIn, stdOut, noStdOut, printDecode, printEncode, printTable, printChisq;
    
    stdIn = 1;
    stdOut = 1;
    noStdOut = 0;
    printDecode = 0;
    printEncode = 0;
    printTable = 0;
    printTable = 0;


    for(i=1 ; argv[i]!=NULL; i++){
        char store[2];
        snprintf( store, sizeof store, "%c", argv[i][0]);
        if(strcmp(store, "-") == 0){
            printf("OK\n");
            char store2[2];
            snprintf( store2, sizeof store2, "%c", argv[i][1]);

            if (strcmp(store2, "F") == 0){
                stdIn = 0;

                char name[2];
                snprintf(name, sizeof name, "%c", argv[i][2]);

                if(strcmp(name, "\0") == 0){
                    snprintf(fileNameIn, sizeof fileNameIn, "%s", argv[i+1]);
                }else{
                    s=0;
                    for(j=2; j<100; j++){
                        fileNameIn[s] = argv[i][j];
                        s++;
                    }
                }
            }

            if(strcmp(store2, "O") == 0){
                stdOut = 0;

                char name2[2];
                snprintf( name2, sizeof name2, "%c", argv[i][2]);

                if(strcmp(name2, "\0") == 0){
                    snprintf(fileNameOut, sizeof fileNameOut, "%s", argv[i+1]);
                }else{
                    s=0;
                    for (j=2; j<100; j++){
                        fileNameOut[s] = argv[i][j];
                        s++;
                    }
                }
            }

            for(j=1; j<6; j++){

                char next[2];
                char next2[2];
                snprintf(next, sizeof next, "%c", argv[i][j]);
                snprintf(next2, sizeof next2, "%c", argv[i][j+1]);

                if(strcmp(next2,"\0") == 0){
                    j=6;
                }

                if(strcmp(next, "s") == 0){
                    printDecode = 1;
                    printf("Shift to decode\n");
                }else if(strcmp(next, "S") == 0){
                    printEncode = 1;
                    printf("Shift to encode\n");
                }else if(strcmp(next, "t") == 0){
                    printTable = 1;
                    printf("print table\n");
                }else if(strcmp(next, "x") == 0){
                    printChisq = 1;
                    printf("print chi_sq\n");
                }else if(strcmp(next, "n") == 0){
                    noStdOut = 1;
                    stdOut = 0;
                    printf("suppress\n");
                }
            }
        }
    }



    




    return 0;
}