/*******************************************************************************
*
* File Name         : misc.h
* Created By        : Thomas Aurel
* Creation Date     : March 10th, 2015
* Last Change       : April 22th, 2015 at 23:10:55
* Last Changed By   : Thomas Aurel
* Purpose           :
*
*******************************************************************************/
/**
 * ls execution.
 * param:   char *dir
 *          char full path to the directory
 * return:  int is_it_ok?i
 *          0 if it fails
 *          1 if it success
 **/
int my_ls(char *dir);

/**
 * wc execution.
 * param:   void 
 * return:  int is_it_ok?i
 *          0 if it fails
 *          1 if it success
 **/
int my_wc(void);

int my_stoi(char *str);
