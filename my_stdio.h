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
int my_putchar(char c);
int my_putnbr(int i, char f, int w);
int my_putnbr_base(int i, int b, int u, char f, int w);
int my_puts(char *str);
int hashspace_flag(char f, int b, int u);

/* my_stdio.1.c */
int my_printf(char *format, ...);
int print_specifier(char c, va_list ap, char f, int w, int p);
int print_flag(char c);
int int_width(int i, int b, int w);

/* my_stdio.2.c */
int my_putdouble(double f, int u, char flag, int w, int p);
int my_putdouble_base(double f, int b, int u, char flag, int w, int p);
