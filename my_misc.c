/*******************************************************************************
 *
 * File Name         : misc.c
 * Created By        : Thomas Aurel
 * Creation Date     : March 10th, 2015
 * Last Change       : March 10th, 2015 at 17:13:33
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
#include "my_misc.h"
#include <unistd.h>

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
