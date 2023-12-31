#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to printf
 *
 * Return: void
 */
int _puts(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
static int i;
static char buff[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buff, i);
i = 0;
}
if (c != BUF_FLUSH)
buff[i++] = c;
return (1);
}
