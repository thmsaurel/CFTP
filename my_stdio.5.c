/*******************************************************************************
 *
 * File Name         : my_stdio.5.c
 * Created By        : Thomas Aurel
 * Creation Date     : April 22th, 2015
 * Last Change       : April 22th, 2015 at 21:05:38
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include "my_stdio.h"

charlist convert_itocl(int i, int b){
    if (i < 0){
        addItem('-', nbr);
        i = (-1) * i;
    }
    if (i > b){
        nbr = concatItem(nbr, convert_itos(i, b));
    } else {
        nbr = addItem(((i%b) < 10 ? '0' + (i % b) : 'a' + (i%b) - 10), nbr);
    }
    return nbr;
}

charlist convert_dtocl(double d, int b){
    charlist* nbr = NULL;
    int i = d;
    d = (d - i) * b;
    nbr = concatItem(nbr, convert_itos(i, b));
    nbe = addItem('.', nbr);
    do{
        i = d;
        d = (d - i) * b;
        nbr = concatItem(nbr, convert_itos(i, b));
    }while(f != 0.0)
    return nbr;
}
