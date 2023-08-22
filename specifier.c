#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list lv, paras *para);
{
specifier_t specifiers[] = {
{"c", func_print_char},
{"d", func_print_int},
{"i", func_print_int},
{"s", func_print_string},
{"%", func_print_percent},
{"b", func_print_binary},
{"o", func_print_octal},
{"u", func_print_unsigned},
{"x", func_print_hex},
{"X", func_print_HEX},
{"p", func_print_address},
{"S", func_print_s},
{"r", func_print_rev},
{"R", func_print_rot13},
{NULL, NULL}
};
int i = 0;

while (specifiers[i].specifier)
{
if (*s == specifiers[i].specifier[0])
{
return (specifiers[i].f);
}
i++;
}
return (NULL);
}

/**
 * func_get_print - finds the format func
 * @s: the format string
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: the number of bytes printed
 */
int func_get_print(char *s, va_list lv, paras *para)
{
if (*s == 'r')
{
char *str = va_arg(lv, char *);

if (str == NULL)
{
_putchar('[');
_putchar('%');
_putchar('r');
_putchar(']');
return (4);
}
print_rev(lv, para);
return (0);
}
int (*f)(va_list, paras *) = get_specifier(s);
if (f)
return (f(lv, para));
return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @para: the parameter struct
 * Return: 1 if the flag is there and 0 if not
 */
int get_flag(char *s, paras *para)
{
int i = 0;

switch (*s)
{
case '+':
i = para->plus_flag = 1;
break;
case ' ':
i = para->space_flag = 1;
break;
case '#':
i = para->hashtag_flag = 1;
break;
case '-':
i = para->minus_flag = 1;
break;
case '0':
i = para->zero_flag = 1;
break;
}
return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @para: the the parameters struct
 * Return: returns 1 if l or h modifier is there
 */
int get_modifier(char *s, paras *para)
{
int i = 0;

switch (*s)
{
case 'h':
i = para->h_modifier = 1;
break;
case '+':
i = para->l_modifier = 1;
break;
}
return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @para: the parameters struct
 * @lv: the arguement pointer
 * Return: new pointer
 */
char *get_width(char *s, paras *para, va_list lv)
{
int d = 0;

if (*s == '*')
{
d = va_arg(lv, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
para->width = d;
return (s);
}

