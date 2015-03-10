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
#include "misc.h"
#include <unistd.h>

int my_ls(int out, char *str){
    return execlp("ls", "ls", 0);
}

int my_wc(int in){
    return execlp("wc", "wc", 0);
}
