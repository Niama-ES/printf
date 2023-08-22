#include "main.h"

/**
 * func_print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int func_print_from_to(char *start, char *stop, char *except)
{
int sum = 0;

while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
 * func_print_rev - prints string in reverse
 * @lv: string
 * @para: the parameters struct
 *
 * Return: number bytes printed
 */
int func_print_rev(va_list lv, paras *para)
{
int len, sum = 0;
char *str = va_arg(lv, char *);
(void)para;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
sum += _putchar(*str);
}
else
{
_putchar('[');
_putchar('%');
_putchar('r');
_putchar(']');
sum = 4;
}
return (sum);
}

/**
 * func_print_rot13 - prints string in rot13
 * @lv: string
 * @para: the parameters struct
 *
 * Return: number bytes printed
 */
int func_print_rot13(va_list lv, paras *para)
{
int i, index;
int count = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM        nopqrstuvwyzabcdefghijklm";
char *a = va_arg(lv, char *);
(void)para;

i = 0;
index = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
{
index = a[i] - 65;
count += _putchar(arr[index]);
}
else
count += _putchar(a[i]);
i++;
}
return (count);
}
