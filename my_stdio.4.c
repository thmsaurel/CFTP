/*******************************************************************************
 *
 * File Name         : my_stdio.4.c
 * Created By        : Thomas Aurel
 * Creation Date     : April 22th, 2015
 * Last Change       : April 22th, 2015 at 21:05:38
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include "my_stdio.h"
#include <stddef.h>
#include <stdlib.h>

char * convert_cltos(charlist list){
    int size_list = listSize(list);
    char* str;
    if((str = (char*) malloc(size_list * sizeof(char))) == NULL){
            my_puts("ERROR: malloc failed\n");
            return NULL;
    }
    for(int i = 0; i < size_list; i++){
        str[i] = list.value;
        free(&list.value);
        list = list->next;
    }
    return str;
}

