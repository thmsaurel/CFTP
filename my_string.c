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

/**
 * find length of string
 *
 * param:   char *str, the line to determine size
 * return:  the line's length
 **/
int my_strlen(char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

/**
 * concatenate strings
 *
 * param:   char *s1, first string
 *          char *s2, second string
 * return:  the pointer on the first string whose is a concatenation of the two param
 **/
char * my_strcat(char *s1, char *s2){
    return my_strncat(s1, s2, my_strlen(s2));
}

/**
 * concatenate strings
 *
 * param:   char *s1, first string
 *          char *s2, second string
 *          int n, the number of character of s2 to concatenate with s1
 * return:  the pointer on the first string whose is a concatenation of the two param
 **/
char * my_strncat(char *s1, char *s2, int n){
    int size = my_strlen(s1);
    char *tmp = malloc((size + n) * sizeof(char));
    for (int i=0; i < size + n; i++){
        if (i < size){
            tmp[i] = s1[i];
        } else {
            tmp[i] = s2[i - size];
        }
    }
    tmp[size + n] = '\0';
    s1 = tmp;
    return s1;
}

/**
 * param:   char *dest, first string
 *          char *src, second string
 * return: the pointer on dest
 **/
char * my_strcpy(char *dest, char *src){
    return my_strncpy(dest, src, my_strlen(src));
}

/**
 * param:   char *dest, first string
 *          char *src, second string
 *          int n, the number of character of src to copy on dest
 * return:  the pointer on dest
 **/
char * my_strncpy(char *dest, char *src, int n){
    char *tmp = malloc(n * sizeof(char));
    for (int i=0; i < n; i++){
        if(i < my_strlen(src)){
            tmp[i] = src[i];
        }else{
            tmp[i] = '\0';
        }
    }
    dest = tmp;
    return dest;
}
