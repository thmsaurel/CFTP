/*******************************************************************************
*
* File Name         : misc.h
* Created By        : Thomas Aurel
* Creation Date     : March 10th, 2015
* Last Change       : March 10th, 2015 at 16:38:25
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
