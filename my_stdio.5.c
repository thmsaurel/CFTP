/*******************************************************************************
 *
 * File Name         : my_stdio.5.c
 * Created By        : Thomas Aurel
 * Creation Date     : April 22th, 2015
 * Last Change       : April 22th, 2015 at 23:10:55
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <stddef.h>
#include "my_stdio.h"
#include "my_string.h"

charlist * convert_itocl(int i, int b){
    charlist *nbr = NULL;
    if (i < 0){
        addItem('-', nbr);
        i = (-1) * i;
    }
    if (i > b){
        nbr = concatItem(nbr, convert_itocl(i, b));
    } else {
        nbr = addItem(((i%b) < 10 ? '0' + (i % b) : 'a' + (i%b) - 10), nbr);
    }
    return nbr;
}

charlist * convert_dtocl(double d, int b){
    charlist *nbr = NULL;
    int i = d;
    d = (d - i) * b;
    nbr = concatItem(nbr, convert_itocl(i, b));
    nbr = addItem('.', nbr);
    do{
        i = d;
        d = (d - i) * b;
        nbr = concatItem(nbr, convert_itocl(i, b));
    }while(d != 0.0);
    return nbr;
}

charlist * convert_stocl(char *s){
    charlist *str = NULL;
    for(int i = 0; i < my_strlen(s); i++){
        str = addItem(s[i], str);
    }
    return str;
}
