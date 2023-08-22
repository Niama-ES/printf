#include "main.h"

/**
 * print_char - prints character
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */

int func_print_char(va_list lv, paras *para)
{
    char pad_char = ' ';
    unsigned int pad = 1 , sum = 0, ch = va_arg(lv, int );

    if (para->minus_flag)
        sum += _putchar(ch);
    while (pad++ < para->width)
        sum += _putchar(pad_char);
    if (!para->minus_flag)
        sum += _putchar(ch);
    return (sum);
}
/**
 * func_print_int - prints integer
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int func_print_int(va_list lv, paras *para)
{
    long l;
    if(para->l_modifier)
        l= va_arg(lv, long);
    else if (para->h_modifier)
        l= (short int)va_arg(lv, int);
    else
        l= (int)va_arg(lv, int);
    return (print_number(convert(l, 10, 0, para), para));

}
/**
 * print_string - prints string
 * @lv: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int func_print_string(va_list lv, paras *para)
{
    char *str = va_arg(lv, char *), pad_char = ' ';
    unsigned int pad = 0, sum = 0, i = 0, j;

    (void)para;
    switch ((int)(str))
case 1:
    str = NULL_STRING;
    j=pad=_strlen(str);
    if(para->precision < pad)
        j = pad = para->precision;
    if(para->minus_flag)
    {
        if(para->precision != UINT_MAX)
            for(i=0;i<pad;i++)
            sum += _putchar(*str++);
        else
            sum += _puts(str);
    }
    while (j++ < para->width)
        sum += _putchar(pad_char);
    if(!para->minus_flag)
    {
        if(para->precision != UINT_MAX)
            for(i=0;i<pad;i++)
            sum += _putchar(*str++);
        else
            sum += _puts(str);
    }
    return (sum);
}
int func_print_percent(va_list lv, paras *para)
{
    (void)lv;
    (void)para;
    return (_putchar('%'));
}
int func_print_s(va_list lv, paras *para)
{
    char *str= va_arg(lv, char *);
    char *hex;
    int sum = 0;
    if((int)(!str))
        return (_puts(NULL_STRING));
    for (; *str; str++)
    {
        if ((*str >0 && *str < 32) || *str >= 127)
        {
            sum += _putchar('\\');
            sum += _putchar('x');
            hex = convert(*str, 16, 0, para);
            if (!hex[1])
                sum += _putchar('0');
            sum += _puts(hex);
        }
        else
        {
            sum += _putchar(*str);
        }
    }
    return (sum);
}

