#include "main.h"

/**
 *convert - converter function,a clone of itoa
 * @num: number
 * @base: base
 * @flags: parameter struct
 * @para: the parameters struct
 * Return: string
 */
char *convert(long int num, int base, int flags, paras *para)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
(void)para;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * func_print_unsigned - print_unsigned integer numbers
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: string
 */
int func_print_unsigned(va_list lv, paras *para)
{
unsigned long l;

if (para->l_modifier)
l = (unsigned long)va_arg(lv, unsigned long);
else if (para->h_modifier)
l = (unsigned short int)va_arg(lv, unsigned int);
else
l = (unsigned int)va_arg(lv, unsigned int);
params->unsign = 1;
return (print_number(convert(l, 10, CONVERT_UNSIGNED, para), para));
}

/**
 *func_print_address - print_address
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int func_print_address(va_list lv, paras *para)
{
unsigned long int n = va_arg(lv, unsigned long int);
char *str;

if (!n)
return (_puts("(nil)"));

str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
*--str = 'x';
*--str = '0';
return (print_number(str, para));
}
