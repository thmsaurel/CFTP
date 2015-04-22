/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : April 22th, 2015 at 21:43:06
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
#include "my_stdio.h"
#include "my_string.h"
#include "my_error.h"
#include "my_libc.h"

/**
 * Functions Definition
 **/
int my_putnbr_base(int i, int b){
    if(verify_inf_size(b, 37) != 0){return -1;}
    return my_puts(convert_cltos(convert_itocl(i, b)));
}

int my_putnbr(int i){
    return my_putnbr_base(i, 10);
}

int my_putdouble_base(double f, int b){
    if(verify_inf_size(b, 37) != 0){return -1;}
    return my_puts(convert_cltos(convert_dtocl(f, b)));
}

int my_putdouble(double f){
    return my_putdouble_base(f, 10);
}
