#include "main.h"

/**
 * func_get_percision - getsthe precision from the format string
 * @p: the format string
 * @para: the parameters struct
 * @lv: the argument poinet
 *
 * Return: new pointer
 */
char *get_precision(char *p, paras *para, va_list lv)
{
    int d = 0;

    if(*p != '.')
        return (p);
    p++;
    if (*p == '*')
    {
        d = va_arg(lv, int);
        p++;
    }
    else
    {
        while (_isdigit(*p))
            d = d *10 + (*p++ - '0');
    }
    para->precision = d;
    return (p);
}

