/*******************************************************************************
 *
 * File Name         : my_stdio.3.c
 * Created By        : Thomas Aurel & Loïc Delaveau
 * Creation Date     : April 22th, 2015
 * Last Change       : April 23th, 2015 at 01:01:47
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include "my_stdio.h"

charlist * addItem(char c, charlist *list){
    charlist *newlist = NULL;
    if((newlist = createItem(c)) == 0){
        my_puts("Error: on createList()");
        return NULL;
    }
    if(list != NULL){
        charlist *lastlist = lastItem(list);
        lastlist->next = newlist;
    } else {
        list = newlist;
    }
    return list;
}

charlist * concatItem(charlist *list, charlist *newlist){
    if(list != NULL){
        charlist *lastlist = lastItem(list);
        lastlist->next = newlist;
    } else {
        list = newlist;
    }
    return list;
}

charlist * createItem(char c){
    charlist *newlist = NULL;
    newlist->value = c;
    newlist->next = NULL;
    return newlist;
}

charlist * lastItem(charlist *list){
    while(list->next != NULL){
        list = list->next;
    }
    return list;
}

int listSize(charlist *list){
    int i = 0;
    while(list != NULL){
        i += 1;
        list = list->next;
    }
    return i;
}
