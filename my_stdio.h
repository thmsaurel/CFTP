/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : April 22th, 2015 at 23:10:55
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>

/* my_stdio.c
 * for default function
 * */

/**
 * output a character or word to a stream
 *
 * param:   char c, the character to write
 * return:  return 1 on success
 **/
int my_putchar(char c);

/**
 * output a line to a stream
 *
 * param:   char *str, the line to write
 * return:  0 on success
 **/
int my_puts(char *str);

/* my_stdio.1.c
 * for number functions
 */
int my_putdouble(double f);
int my_putdouble_base(double f, int b);

/**
 * output a number on base 10
 *
 * param:   int i, the integer to write
 * return:  0 on success, else -1
 **/
int my_putnbr(int i);

/**
 * output a number on a base
 *
 * param:   int i, the integer to write
 *          int b, the base to the character
 * return:  0 on success, else -1
 **/
int my_putnbr_base(int i, int b);

/* my_stdio.2.c */
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
char * print_specifier(char s, va_list ap, char *f, char *w, char *p);
int print_flag(char c);
/**
 * Calculate and print a string of '0' according to the width specified in the printf funtion.
 *
 * param: int i, int b, int w
 * return: int nb_char_printed
 **/
int int_width(int i, int b, int w);

/* my_stdio.3.c
 * miscs functions about charlist
 */
typedef struct charlist{
    char value;
    struct charlist *next;
} charlist;

charlist * addItem(char c, charlist *list);
charlist * concatItem(charlist *list, charlist *newlist);
charlist * createItem(char c);
charlist * lastItem(charlist *list);
int listSize(charlist *list);

/* my_stdio.4
 * miscs functions about charlist 2
 */
char * convert_cltos(charlist *list);
charlist * apply_f(charlist *list, char *f);
charlist * apply_w(charlist *list, char *w, char *f);
charlist * apply_p(charlist *list, char *p);

/* my_stdio.5.c
 * convert type to charlist
 */

/**
 * convert a number (int or double) into a string
 *
 * param:   double d, the integer or double to convert
 * param:   int b, the number base
 * return:  charlist on success
 **/
charlist * convert_itocl(int i, int b);
charlist * convert_dtocl(double d, int b);
charlist * convert_stocl(char *s);
