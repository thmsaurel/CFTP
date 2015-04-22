/*******************************************************************************
 *
 * File Name         : my_stdio.3.c
 * Created By        : Thomas Aurel & Loïc Delaveau
 * Creation Date     : April 22th, 2015
 * Last Change       : April 22th, 2015 at 01:57:35
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include "my_stdio.h"

charlist addItem(char c, charlist list){
    charlist newlist;
    if((newlist = createList(c)) == 0){
        my_puts("Error: on createList()");
        return 0;
    }
    if(list != NULL){
        charlist lastlist = lastItem(list);
        lastlist->next = newlist;
    } else {
        list = newlist;
    }
    return list;
}

charlist createList(char c){
    charlist newlist;
    if((newlist.value = malloc(sizeof(char))) == NULL){
        my_puts("Error: out of memory");
        return 0;
    }
    newlist.value = c;
    newlist->next = NULL;
    return newlist;
}

charlist lastItem(charlist list){
    while(list.next != NULL){
        list = list->next;
    }
    return list;
}

charlist concatItem(charlist list, charlist newlist){
    if(list != NULL){
        charlist lastlist = lastItem(list);
        lastlist->next = newlist;
    } else {
        list = newlist;
    }
    return list;
}
