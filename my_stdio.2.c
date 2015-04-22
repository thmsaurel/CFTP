/*******************************************************************************
 *
 * File Name         : my_stdio.2.c
 * Created By        : Thomas Aurel
 * Creation Date     : February 28th, 2015
 * Last Change       : April 23th, 2015 at 00:32:12
 * Last Changed By   : Thomas Aurel
 * Purpose           : standard input/output library functions
 *
 * Filetype          : vim: filetype=c
 *
 *******************************************************************************/
#include <stdarg.h>
#include <stddef.h>
#include "my_stdio.h"
#include "my_string.h"
#include "my_error.h"
/**
 * This is documentation for my_printf function.
 *
 * PRINTF Constructor :
 * %[flags][width][.precision][length]specifier
 *
 * flags :
 *    DONE: +, #
 *    TODO: -, ' ', 0
 *
 * width : \w
 *    TODO: *
 *
 * precision : \w
 *    TODO: .*
 *
 *
 * specifier :
 *    DONE: c, s, %, d, i, o, x, X, f, F
 *    TODO: u, e, E, g, G, p, a, A, n
 *
 **/

/*
 * Global const for printf.
 */
int G_flags_size = 5;
char G_flags[5] = {
    '-', '+', ' ', '#', '0'
};

int G_width_size = 11;
char G_width[11] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
};

int G_precision_size = 12;
char G_precision[12] = {
    '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'
};

int G_specifier_size = 11;
char G_specifier[11] = {
    'c', 's', '%', 'd', 'i', 'o', 'x', 'X', 'f', 'F'
};

char * print_specifier(char s, va_list ap, char *f, char *w, char *p){
    charlist *result = NULL;
    char *str;
    if (s == '%' || s == 'c'){
        result = addItem((s == '%' ? '%' : (char) va_arg(ap, int)), result);
    } else if(s == 's'){
        result = concatItem(convert_stocl(va_arg(ap, char*)), result);
    } else if(s == 'i' || s == 'd'){
        result = concatItem(convert_itocl(va_arg(ap, int), 10), result);
    } else if(s == 'o'){
        result = concatItem(convert_itocl(va_arg(ap, int), 8), result);
    } else if(s == 'x' || s == 'X'){
        result = concatItem(convert_itocl(va_arg(ap, int), 16), result);
    } else if(s == 'f'  || s == 'F'){
        result = concatItem(convert_dtocl(va_arg(ap, double), 10), result);
    }
    if(s != '%' && s != 'c' && s != 's'){
        if(s == 'f' || s == 'F'){
            str = convert_cltos(apply_p(apply_w(apply_f(result, f), w, f), p));
        } else {
            str = convert_cltos(apply_w(apply_w(apply_f(result, f), w, f), p, "0"));
        }
    } else { str = convert_cltos(result); }
    return ((s == 'X' || s == 'F' ? my_strcapitalize(str) : str));
}

int my_printf(char *format, ...){
    int text_size = my_strlen(format);
    va_list ap;
    charlist *flaglist = NULL, *widthlist = NULL, *precisionlist = NULL;
    va_start(ap, format);
    for(int i=0; i<text_size; i++){
        if (format[i] == '%'){
            i += 1;
            while(verify_char_tab(format[i], G_flags, G_flags_size)){
                flaglist = addItem(format[i], flaglist);
                i += 1;
            }
            while(verify_char_tab(format[i], G_width, G_width_size)){
                widthlist = addItem(format[i], widthlist);
                i += 1;
            }
            while(verify_char_tab(format[i], G_precision, G_precision_size)){
                precisionlist = addItem(format[i], precisionlist);
                i += 1;
            }
            if(verify_char_tab(format[i], G_specifier, G_specifier_size) == 0){
                my_puts("ERROR: Unknow printf specifier");
                return 1;
            }
            my_puts(print_specifier(
                        format[i], ap,
                        convert_cltos(flaglist), convert_cltos(widthlist),
                        convert_cltos(precisionlist)));
        } else {my_putchar(format[i]);};
    }
    va_end(ap);
    return 0;
}

