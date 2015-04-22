/*******************************************************************************
 *
 * File Name         : my_math.c
 * Created By        : Thomas Aurel
 * Creation Date     : January  9th, 2015
 * Last Change       : April  8th, 2015 at 23:23:37
 * Last Changed By   : Unknow Maintainer
 * Purpose           :
 *
 *******************************************************************************/
#include "my_math.h"

int my_pow(int i, int p){
    int a = 1;
    for(int j=0;j<p;j++){a = a * i;}
    return a;
}

