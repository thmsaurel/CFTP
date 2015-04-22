/*******************************************************************************
 *
 * File Name         : my_stdio.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : April 22th, 2015 at 00:49:04
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions (second file)
 *
 *******************************************************************************/
#include <stddef.h>
#include "my_stdio.h"
#include "my_string.h"
#include "my_error.h"
#include "my_libc.h"

/**
 * Functions Definition
 **/
char* convert_ntos(double d, int b){
    charlist* nbr = NULL;
    int i = d;
    if (d < 0){
        addItem('-', nbr);
        d = (-1) * d;
    }
    if (i > b){
        nbr = concatItem(nbr, convert_ntos((double) i, b));
    } else {
        nbr = addItem(((i%b) < 10 ? '0' + (i % b) : 'a' + (i%b) - 10), nbr);
    }
    d = (d - i) * b;
    if (d != 0.0){
        nbe = addItem('.', nbr);
        do{
            i = d;
            d = (d - i) * b;
            nbr = concatItem(nbr, convert_ntos((double) i, b));
        }while(f != 0.0)
    }
    return nbr;
}

    int my_putnbr_base(int i, int b){
        int str_size = 0;
        if(verify_inf_size(b, 37) != 0){return -1;}
        return my_puts(convert_ntos((double) i, b));
    }

    int my_putnbr(int i){
        return my_putnbr_base(i, 10);
    }

    int my_putdouble_base(double f, int b){
    if(verify_inf_size(b, 37) != 0){return -1;}
    return my_puts(convert_ntos(d, b));
    }

    /**
     *
     **/
    int my_putdouble(double f){
        return my_putdouble_base(f, 10, u, flag, w, p);
    }
