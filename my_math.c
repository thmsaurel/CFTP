/*******************************************************************************
 *
 * File Name         : my_math.c
 * Created By        : Thomas Aurel
 * Creation Date     : January  9th, 2015
 * Last Change       : February 23th, 2015 at 23:41:01
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include "my_math.h"
/**
 * power function
 *
 * param:   int i, integer to raised
 *          int p, the power
 * return:  int, integer i to the power p on success, else -1
 **/
int my_pow(int i, int p){
        int a = 1;
        if(p > 0){
                for(int j=0;j<p;j++){a = a * i;}
        } else if(p < 0){
                for(int j=p;j>0;j--){a = a / i;}
        }
        return a;
}

