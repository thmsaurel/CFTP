/*******************************************************************************
*
* File Name         : my_stdio.h
* Created By        : Thomas Aurel
* Creation Date     : January 15th, 2015
* Last Change       : April 28th, 2015 at 23:23:45
* Last Changed By   : Thomas Aurel
* Purpose           : standard input/output library functions
*
*******************************************************************************/
#include <stdarg.h>

/* my_stdio.c
 * for default function
 */

/**
 * output a character or word to a stream
 *
 * param:   char c, the character to write
 * return:  1 on success
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

/**
 * output a double to a stream
 *
 * param:    double f, the double to write
 * return:  0 on success
 **/
int my_putdouble(double f);

/**
 * output a double to a stream into a determine base
 *
 * param:   double f, the double to write
 *          int b, the base for the writing
 * return:  0 in success
 **/
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
 *    -Characters
 *    -Conversion specifications (that begin by %) and contain:
 *       -(optional) flags, to format output
 *       -(optional) width
 *       -(optional) precision
 *       -A specifier that indicate what kind of data must be printed
 *
 * param:   char *format, string to write on stdout
 *          (optional) ..., the values to complete text
 * return:  0 on success, else 1
 **/
int my_printf(char *format, ...);

/**
 * use to determine the specifier and options to apply
 *
 * param:   char s, the specifier who determine the data to transform
 *          va_list ap, the list of optional arguments
 *          char *f, a list of flag character to apply on the return string
 *          char *w, a list of width character to apply on the return string
 *          char *p, a list of precision character to apply on the return string
 * return:  return the string on success, else NULL
 **/
char * print_specifier(char s, va_list ap, char *f, char *w, char *p);

/* my_stdio.3.c
 * miscs functions about charlist
 */

typedef struct charlist{
    char value;
    struct charlist *next;
} charlist;

/**
 * Add a char c into at the end of a list
 *
 * param:   char c, the character to add to the list
 *          charlist *list, the list
 * return:  the new charlist with the character
 **/
charlist * addItem(char c, charlist *list);

/**
 * Concatenate two charlist into one
 *
 * param:   charlist *list, one of the two charlist to concatenate
 *          charlist *newlist, the others
 * return:  the new charlist composed with the two original charlist
 **/
charlist * concatItem(charlist *list, charlist *newlist);

/**
 * Create a new charlist with the character c
 *
 * param:   char c, the character to put into the charlist
 * return:  the new charlist item with the c value
 **/
charlist * createItem(char c);

/**
 * Give the last item of a list
 *
 * param:   charlist *list, a charlist
 * return:  the last element of the previous list
 **/
charlist * lastItem(charlist *list);

/**
 * Give the size of a charlist
 *
 * param:   charlist *list, a charlist
 * return:  the number of charlist element
 **/
int listSize(charlist *list);

/* my_stdio.4
 * miscs functions about charlist 2
 */

/**
 * Convert a charlist into a string
 *
 * param:   charlist *list, the charlist to convert
 * return:  the list convert to string on success, else NULL
 **/
char * convert_cltos(charlist *list);

/**
 * Apply flags on a charlist
 *
 * param:   charlist *list, the charlist whithout flags
 *          char *f, the flags list
 * return:  the new charlist with flags on success
 **/
charlist * apply_f(charlist *list, char *f);

/**
 * Apply width on a charlist
 *
 * param:   charlist *list, the charlist whithout width
 *          char *w, the widths list
 *          char *f, the flags list
 * return:  the new charlist with width on success
 **/
charlist * apply_w(charlist *list, char *w, char *f);

/**
 * Apply precision on a charlist
 *
 * param:   charlist *list, the charlist whithout precision
 *          char *p, the precision list
 * return:  the new charlist with precision on success
 **/
charlist * apply_p(charlist *list, char *p);

/* my_stdio.5.c
 * convert type to charlist
 */

/**
 * convert an integer into a charlist
 *
 * param:   int i, the integer to convert
 * param:   int b, the number base
 * return:  charlist on success
 **/
charlist * convert_itocl(int i, int b);

/**
 * convert a double into a charlist
 *
 * param:   double d, the double to convert
 * param:   int b, the number base
 * return:  charlist on success
 **/
charlist * convert_dtocl(double d, int b);

/**
 * convert a string into a charlist
 *
 * param:   char *s, the string to convert
 * return:  charlist on success
 **/
charlist * convert_stocl(char *s);
