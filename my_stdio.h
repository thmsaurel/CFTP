/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : March  2th, 2015 at 15:00:11
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>

/* my_stdio.c */

/**
 * output a character or word to a stream
 *
 * param:   char c, the character to write
 * return:  return 1 on success
 **/
int my_putchar(char c);

/**
 * output a number on base 10
 *
 * param:   int i, the integer to write
 * return:  0 on success, else -1
 **/
int my_putnbr(int i, char f, int w);

/**
 * output a number on a base
 *
 * param:   int i, the integer to write
 *          int b, the base to the character
 *          int u, 1 if upper, 0 else
 *          char f, the flag character
 * return:  0 on success, else -1
 **/
int my_putnbr_base(int i, int b, int u, char f, int w);

/**
 * output a line to a stream
 *
 * param:   char *str, the line to write
 * return:  0 on success
 **/
int my_puts(char *str);

int hashspace_flag(char f, int b, int u);

/* my_stdio.1.c */

/**
 * This is the main function for printf. Print a string on stdout that contain:
 *  -Characters
 *  -Conversion specifications (that begin by %) and contain:
 *      -(optional)flags, to format output
 *      -(optional)width
 *      -(optional)precision
 *      -A specifier that indicate what kind of data must be printed
 *
 * param: char *format, ...
 *        String that shall be printed after processing it, followed (the "..."in the param filed) by values to be printed
 * return: A lovely poney
 **/
int my_printf(char *format, ...);

/**
 * Print a specifier (in printf means) by poping from a va_list with the good
 * flag, width and precision
 *
 * param:   char c, va_list ap, char f, int w, int p
 *          char specifier, va_list argument_pointer, char flag, int width, 
 *              int precision
 * return: Your mother...
 **/
int print_specifier(char c, va_list ap, char f, int w, int p);
int print_flag(char c);
/**
 * Calculate and print a string of '0' according to the width specified in the printf funtion.
 *
 * param: int i, int b, int w
 * return: int nb_char_printed
 **/
int int_width(int i, int b, int w);

/* my_stdio.2.c */
int my_putdouble(double f, int u, char flag, int w, int p);
int my_putdouble_base(double f, int b, int u, char flag, int w, int p);
