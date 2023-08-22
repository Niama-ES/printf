#include "main.h"

/**
 * _printf - Printf function
 * @format: the format string.
 *
 * Return: number of bytes printed.
 */

int _printf(const char *format, ...)
{
    int sum = 0;
    va_list lv;
    char *p, *start;
    paras para = PARAMS_INIT;

    va_start(lv, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (p = (char *)format; *p; p++)
    {
        func_init_params(&para, lv);
        if (*p != '%')
        {
            sum += _putchar(*p);
            continue;
        }
        start = p;
        p++;
        while (func_get_flag(p, &para))
        {
            p++;
        }
        p = get_width(p, &para, lv);
        p = get_precision(p, &para, lv);
        if (func_get_modifier(p, &para))
            p++;
        if(!get_specifier(p))
            sum += func_print_from_to(start, p, para.l_modifier || para.h_modifier ? p - 1 : 0);
        else
            sum += func_get_print(p, lv, &para);
    }
    _putchar(BUF_FLUSH);
    va_end(lv);
    return (sum);
}

