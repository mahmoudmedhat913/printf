#include "main.h"

/**
 * print_from_to - print range
 * @start: start address
 * @stop: stop address
 * @except: except address
 * Return: no. of printed bytes
 */

int print_from_to(char *start, char *stop, char *except)
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
 * print_rev - print reverse string
 * @ap: string
 * @params: parameter structure
 * Return: no. of printed bytes
 */

int print_rev(va_list ap, params_t *params)
{
	int i, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (i = 0; *str; str++)
			i++;
		str--;
		for (; i > 0; i--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - print string in rot13
 * @ap: string
 * @params: parameter structure
 * Return: no. of printed bytes
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, j, count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM        nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	j = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			j = a[i] - 65;
			count += _putchar(array[j]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
