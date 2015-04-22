/*******************************************************************************
 *
 * File Name         : my_stdio.4.c
 * Created By        : Thomas Aurel
 * Creation Date     : April 22th, 2015
 * Last Change       : April 23th, 2015 at 00:58:49
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <stddef.h>
#include <stdlib.h>
#include "my_misc.h"
#include "my_stdio.h"
#include "my_string.h"

char * convert_cltos(charlist * list){
    int size_list = listSize(list);
    char* str;
    if((str = (char*) malloc(size_list * sizeof(char))) == NULL){
        my_puts("ERROR: malloc failed\n");
        return NULL;
    }
    for(int i = 0; i < size_list; i++){
        str[i] = list->value;
        free(&list->value);
        list = list->next;
    }
    return str;
}

charlist * apply_f(charlist *list, char *f){
    for(int i = 0; i < my_strlen(f); i++){
        if((f[i] == '+' || f[i] == ' ') && list->value != '-'){
            charlist *newlist = createItem(f[i]);
            newlist->next = list;
            list = newlist;
        } else if(f[i] == '#'){
            charlist *newlist = list;
            while(newlist->next != NULL || newlist->value != '.'){
                newlist = newlist->next;
            }
            if(newlist->value == '.'){ newlist = addItem('x', createItem('0'));
            } else { newlist = createItem('0'); }
            if (list->value == '+' || list->value == '-' || list->value == '-'){
                newlist->next = list->next;
                list->next = newlist;
            } else {
                newlist->next = list;
                list = newlist;
            }
        }
    }
    return list;
}
charlist * apply_w(charlist *list, char *w, char *f){
    int width = my_stoi(w), flag = 0;
    for(int i = 0; i < my_strlen(f) || flag != 0; i++){
        if(f[i] == '-'){ flag = 2; }
        else if (f[i] == '0'){ flag = 1; }
    }
    for(int i = listSize(list); i < width; i++){
        if(flag > 1){list = addItem(' ', list);}
        else {
            charlist *newlist = createItem((flag = 0 ? ' ' : '0'));
            newlist->next = list;
            list = newlist;
        }
    }
    return list;
}
charlist * apply_p(charlist *list, char *p){
    int precision = my_stoi(convert_cltos(convert_stocl(p)->next));
    charlist *newlist = list;
    while(newlist->next != NULL && newlist->value != '.'){
        newlist = newlist->next;
    }
    if(newlist->next == NULL){ newlist = addItem('.', newlist); }
    for(int i = 0; i < precision; i++){
        if(newlist->next == NULL){ newlist = addItem('0', newlist); }
    }
    newlist->next = NULL;
    return list;
}

