/*******************************************************************************
 *
 * File Name         : my_string.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 15th, 2015
 * Last Change       : January 18th, 2015 at 23:37:22
 * Last Changed By   : Thomas Aurel
 * Purpose           : string specific functions
 *
 *******************************************************************************/

#include <stdlib.h>
#include "my_stdio.h"
#include "my_string.h"
int my_strlen(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

char * my_strcat(char *s1, char *s2){
    return my_strncat(s1, s2, my_strlen(s2));
}

char * my_strncat(char *s1, char *s2, int n){
    int size = my_strlen(s1);
    char *tmp;
    if ((tmp = (char *)malloc((size+n)*sizeof(char)))==NULL){
      my_puts("ERROR: malloc failed\n");
      return NULL;
    }
    for (int i=0; i < size + n; i++){
        if (i < size){
            tmp[i] = s1[i];
        } else {
            tmp[i] = s2[i - size];
        }
    }
    tmp[size + n] = '\0';
    s1 = tmp;
    free(tmp);
    return s1;
}

char * my_strcpy(char *dest, char *src){
    return my_strncpy(dest, src, my_strlen(src));
}

char * my_strncpy(char *dest, char *src, int n){
    char *tmp;
    if ((tmp = (char *)malloc(n*sizeof(char)))==NULL){
      my_puts("ERROR: malloc failed\n");
      return NULL;
    }
    for (int i=0; i < n; i++){
        if(i < my_strlen(src)){
            tmp[i] = src[i];
        }else{
            tmp[i] = '\0';
        }
    }
    dest = tmp;
    free(tmp);
    return dest;
}
