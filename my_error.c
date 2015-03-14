/*******************************************************************************
 *
 * File Name         : error.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 31th, 2015
 * Last Change       : March 10th, 2015 at 17:28:12
 * Last Changed By   : Thomas Aurel
 * Purpose           : Configure C error
 *
 *******************************************************************************/
#include <unistd.h>
#include <stdlib.h>
#include "my_string.h"
int return_verification_int(int result, int exp){
    if(result != exp){
        write(1, "Error: return size unexpected", 28*sizeof(char));
        exit(1);
    }
    return 1;
}

int verify_inf_size(int value, int expected){
    if(value > expected){
        write(1, "Error: size too big", 19*sizeof(char));
        exit(2);
    }
    return 0;
}

int verify_char_tab(char c, char* tab, int tsize){
    int result = 0;
    for(int i=0; i<tsize; i++){
        if(c == tab[i]){
            result = 1;
        }
    }
    return result;
}

int verify_char(char c1, char c2){
    if (c1 == c2){
        write(1, "Error: Unexpected character", 27*sizeof(char));
        exit(3);
    }
    return 1;
}
