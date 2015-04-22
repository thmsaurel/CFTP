/*******************************************************************************
 *
 * File Name         : misc.c
 * Created By        : Thomas Aurel
 * Creation Date     : March 10th, 2015
 * Last Change       : April 22th, 2015 at 23:10:55
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include <unistd.h>
#include "my_misc.h"
#include "my_string.h"
#include "my_math.h"

int my_ls(char *dir){
    if ((execlp("ls", dir, (char *)NULL))==-1)
      return 0;
    return 1;
}

int my_wc(void){
    if ((execlp("wc", "wc", (char *)NULL))==-1)
      return 0;
    return 1;
}

int my_stoi(char *str){
    int result = 0;
    for(int i = 0; i < my_strlen(str); i++){
        result += my_pow((int) str[i], my_strlen(str) - i);
    }
    return result;
}

