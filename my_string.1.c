/*******************************************************************************
 *
 * File Name         : my_string.1.c
 * Created By        : Thomas Aurel
 * Creation Date     : January 18th, 2015
 * Last Change       : January 19th, 2015 at 00:05:39
 * Last Changed By   : Thomas Aurel
 * Purpose           : string specific functions (second file)
 *
 *******************************************************************************/
#include <stdlib.h>
#include "my_stdio.h"
#include "my_string.h"

char * my_strcapitalize(char *str){
    char *string;
    if ((string=(char *)malloc(my_strlen(str)*sizeof(char)))==NULL){
      my_puts("ERROR: malloc failed\n");
      return 0;
    }
    for(int i = 0; i < my_strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            string[i] = 'A' + str[i] - 'a';
        } else {
            string[i] = str[i];
        }
    }
    return string;
}

int my_strcmp(char *s1, char *s2){
    return my_strncmp(s1, s2, my_strlen(s2));
}

int my_strncmp(char *s1, char *s2, int n){
    int i = 0;
    my_puts("\n");
    while(s1[i] == s2[i]){
        my_printf("s1 : %c\ns2 : %c\n", s1[i], s2[i]);
        i++;
    }
    return i-n;
}
