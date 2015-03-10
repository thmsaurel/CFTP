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
/**
 * verify if a return size is the expected value
 *
 * param:   int result, return value
 *          int expected, expected value
 * return:  return 1 if result == expected
 **/
int return_verification_int(int result, int exp){
    if(result != exp){
        write(1, "Error: return size unexpected", 28*sizeof(char));
        exit(1);
    }
    return 1;
}

/**
 * verify is size is not too big
 *
 * param:   int value, size given
 *          int expected, size expected
 * return:  return 0 if value < expected
 **/
int verify_inf_size(int value, int expected){
    if(value > expected){
        write(1, "Error: size too big", 19*sizeof(char));
        exit(2);
    }
    return 0;
}

/**
 * verify if char c is in tab
 *
 * param:   char c, char given
 *          char* tab, char value
 * return:  return 1 if c is in tab
 **/
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

