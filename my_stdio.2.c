/*******************************************************************************
 *
 * File Name         : my_stdio.2.c
 * Created By        : Thomas Aurel
 * Creation Date     : February 28th, 2015
 * Last Change       : March  2th, 2015 at 22:06:43
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 * Filetype          : vim: filetype=c
 *
 *******************************************************************************/
#include "my_stdio.h"
/**
 *
 **/
int my_putdouble_base(double f, int b, int u, char flag, int w, int p){
    int i = f, max = 0;
    f = (f - i) * b;
    my_putnbr_base(i, b, u, flag, 0);
    if (f != 0.0 || flag == '#' || p > 0){
        my_putchar('.');
        w = w-1;
        do{
            i = f;
            f = (f - i) * b;
            my_putnbr_base(i, b, u, '1', 0);
            w = w-1;
            p = p-1;
        }while(f != 0);
    max = (w > p ? w : p);
    if (max > 0){
        do{
            my_putchar('0');
            max -= 1;
        }while(max != 0);
    }
    }
    return 0;
}

/**
 *
 **/
int my_putdouble(double f, int u, char flag, int w, int p){
    return my_putdouble_base(f, 10, u, flag, w, p);
}
