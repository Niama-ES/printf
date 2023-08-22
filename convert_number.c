#include "main.h"

/**
 * func_print_hex - prints unsigned hex numbers in lowercase
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
*/
int func_print_hex(va_list lv, paras *para)
{
unsigned long l;
int c = 0;
char *str;

if (para->l_modifier)
	l = (unsigned long)va_arg(lv, unsigned long);
else if (para->h_modifier)
	l = (unsigned short int)va_arg(lv, unsigned int);
else
	l = (unsigned int)va_arg(lv, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
if (para->hashtag_flag && l)
{
	*--str = 'x';
	*--str = '0';
}
para->unsign = 1;
return (c += func_print_number(str, para));
}

/**
 * func_print_HEX - prints unsigned HEX numbers in uppercase
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
*/
int func_print_HEX(va_list lv, paras *para)
{
unsigned long l;
int c = 0;
int *str;

if (para->l_modifier)
	l = (unsigned long)va_arg(lv, unsigned long);
else if (para->h_modifier)
	l = (unsigned short int)va_arg(lv, unsigned int);
else
	l = (unsigned int)va_arg(lv, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED, para);
if (para->hashtag_flag && l)
{
	*--str = 'x';
	*--str = '0';
}
para->unsign = 1;
return (c += func_print_number(str, para));
}

/**
 * func_print_binary - prints unsigned binary number
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
*/
int func_print_binary(va_list lv, paras *para)
{
unsigned int n = va_arg(lv, unsigned int);
char *str = convert(n, 2, CONVERT_UNSIGNED, para);
int c = 0;

if (para->hashtag_flag && n)
	*--str = '0';
para->unsign = 1;
return (c += func_print_number(str, para));
}

/**
 * func_print_octal - prints unsigned octal numbers
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
*/
int func_print_octal(va_list lv, paras *para)
{
unsigned long l;
char *str;
int c = 0;

if (para->l_modifier)
	l = (unsigned long)va_arg(lv, unsigned long);
else if (para->h_modifier)
	l = (unsigned short int)va_arg(lv, unsigned int);
else
	l = (unsigned int)va_arg(lv, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, para);

if (para->hashtag_flag && l)
	*--str = '0';
para->unsign = 1;
return (c += func_print_number(str, para));
}
