/*******************************************************************************
 *
 * File Name         : my_libc.c
 * Created By        : Thomas Aurel
 * Creation Date     : January  9th, 2015
 * Last Change       : January 16th, 2015 at 09:35:27
 * Last Changed By   : Thomas Aurel
 * Purpose           : Default C library
 *
 *******************************************************************************/
#include "my_libc.h"
/**
 * integer absolute value function
 *
 * param:   int i
 * return:  int, returns the absolute value
 **/
int my_abs(int i){
    if(i <0){
        i = -i;
    }
    return i;
}
