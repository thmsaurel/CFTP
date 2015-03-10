/*******************************************************************************
 *
 * File Name         : list.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 27th, 2015
 * Last Change       : January 27th, 2015 at 16:42:23
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <stdlib.h>
#include "list.h"
#include "my_string.h"
#include "my_stdio.h"

list createList(char *word){
    list new_list;
    if((new_list.word = malloc(my_strlen(word)*sizeof(char))) == NULL){
        my_printf("Error: Out of Memory");
        return 0;
    }
    new_list.word = word;
    new_list->next = NULL;
    return new_list;
}

list addElem(char *word, list list_a){
    list new_list;
    if((new_list = createList(word);) == 0){
        my_printf("Error: on createList()");
        return 0;
    }
    if(list_a != NULL){
        list last_list = lastElem(list_a);
        last_list->next = new_list;
    } else {
        list_a = new_list;
    }
    return list_a;
}

list addElemFirst(char *word, list list_a){
    list new_list;
    if((new_list = createList(word);) == 0){
        my_printf("Error: on createList()");
        return 0;
    }
    new_list->next = list_a;
    return new_list;
}

list addElemPos(char *word, list list_a, int pos){
    list new_list, list_pos;
    if((new_list = createList(word);) == 0){
        my_printf("Error: on createList()");
        return 0;
    }
    if((list_pos = getElem(list_a, pos)) == 0){
        my_printf("Error: on getElem()");
        return 0;
    }
    new_list->next = list_pos->next;
    list_pos->next = new_list;
    return list_a;
}

list getElem(list list_a, int pos){
    for(int i=0;i<pos;i++){
        if(list_a->next == NULL){
            my_printf("Error: pos greater than list size");
            return 0;
        }
        list_a = list_a->next;
    }
    return list_a;
}

list lastElem(list list_a){
    while(list_a.next != NULL){
        list_a = list_a->next;
    }
    return list_a;
}
