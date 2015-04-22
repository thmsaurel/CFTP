/*******************************************************************************
 *
 * File Name         : my_stdio.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 15th, 2015
 * Last Change       : April 21th, 2015 at 23:16:01
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 *******************************************************************************/
#include <unistd.h>
#include "my_error.h"
#include "my_string.h"
#include "my_stdio.h"

int my_putchar(char c){
    return return_verification_int(write(1, &c, sizeof(char)), 1);
}

int my_puts(char *str){
    for(int i = 0; i < my_strlen(str); i++){
        my_putchar(str[i]);
    }
    return 0;
}

