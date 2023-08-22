#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "null"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED     2

/**
* struct parameters - parameters struct
* @unsign: flag if unsigned value
* @plus_flag: on if plus_flag specified
* @space_flag: on if hashtag_flag specified
* @hashtag_flag: on if _flag specified
* @zero_flag: on if _flag specified
* @minus_flag: on if _flag specified
* @width: field precision specified
* @precision: field precision specified
* @h_modifier: on if h_modifier is specified
* @l_modifier: on if h_modifier is specified
*
*/

typedef struct parameters
{
unsigned int unsign       : 1;
unsigned int plus_flag    : 1;
unsigned int space_flag   : 1;
unsigned int hashtag_flag : 1;
unsigned int zero_flag    : 1;
unsigned int minus_flag   : 1;
unsigned int width;
unsigned int precision;
unsigned int h_modifier   : 1;
unsigned int l_modifier   : 1;
} paras;

/**
* struct specifier - struct token
* @specifier: format token
* @f: the function associated
*/
typedef struct specifier
{
char *specifier;
int (*f)(va_list, paras *);
} specifier_t;

/* _puts.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int func_print_char(va_list lv, paras *para);
int func_print_int(va_list lv, paras *para);
int func_print_string(va_list lv, paras *para);
int func_print_percent(va_list lv, paras *para);
int func_print_s(va_list lv, paras *para);

/*number.c module */
char *convert(long int num, int base, int flags, paras *para);
int func_print_unsigned(va_list lv, paras *para);
int func_print_address(va_list lv, paras *para);

/* specifier.c module */
int *get_specifier(char *s)(va_list lv, paras *para);
int func_get_print(char *s, va_list lv, paras *para);
int func_get_flag(char *s, paras *para);
int func_get_modifier(char *s, paras *para);
char *get_width(char *s, paras *para, va_list lv);

/* convert_number.c module */
int func_print_hex(va_list lv, paras *para);
int func_print_HEX(va_list lv, paras *para);
int func_print_binary(va_list lv, paras *para);
int func_print_octal(va_list lv, paras *para);

/* simple_printers.cmodule */
int func_print_from_to(char *start, char *stop, char *except);
int func_print_rev(va_list lv, paras *para);
int func_print_rot13(va_list lv, paras *para);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int func_print_number(char *str, paras *para);
int func_print_number_right_shift(char *str, paras *para);
int func_print_number_left_shift(char *str, paras *para);

/* params.c module */
void func_init_params(paras *para, va_list lv);

/*string_filds.c modoule */
char *get_precision(char *p, paras *para, va_list lv);

/* _print.c module */
int _printf(const char *format, ...);

#endif
