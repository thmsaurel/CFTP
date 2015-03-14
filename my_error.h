/*******************************************************************************
*
* File Name         : error.h
* Created By        : Thomas Aurel
* Creation Date     : January 31th, 2015
* Last Change       : March  1th, 2015 at 23:06:52
* Last Changed By   : Thomas Aurel
* Purpose           : Configure C error
*
*******************************************************************************/

/**
 * verify if a return size is the expected value
 *
 * param:   int result, return value
 *          int expected, expected value
 * return:  return 1 if result == expected
 **/
int return_verification_int(int res, int exp);

/**
 * verify is size is not too big
 *
 * param:   int value, size given
 *          int expected, size expected
 * return:  return 0 if value < expected
 **/
int verify_inf_size(int value, int expected);

/**
 * verify if char c is in tab
 *
 * param:   char c, char given
 *          char* tab, char value
 * return:  return 1 if c is in tab
 **/
int verify_char_tab(char c, char* tab, int tsize);

/**
 * verify if char c1 is equals to char c2
 *
 * param:   char c1, char c2
 *          char c1, char c2
 * return:  return 1 if c1==c2, otherwise it exits the programm.
 **/
int verify_char(char c1, char c2);

