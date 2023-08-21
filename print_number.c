#include "main.h"

/**
 * _isdigit - check if character is digit
 * @c: char
 * Return: 1 if digit and 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - count length of the string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - print a number with options
 * @str: base no. as string
 * @params: parameter structure
 * Return: char
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int negative = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
	{
		while (i++ < params->precision)
			*--str = '0';
	}
	if (negative)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - print a number with options
 * @str: base no. as a string
 * @params: parameter structure
 * Return: char
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, negative1, negative2, i = _strlen(str);
	char c = ' ';

	if (params->zero_flag && !params->minus_flag)
		c = '0';
	negative1 = (!params->unsign && *str == '-');
	negative2 = (!params->unsign && *str == '-');
	if (negative1 && i < params->width && c == '0' && !params->minus_flag)
		str++;
	else
		negative1 = 0;
	if ((params->plus_flag && !negative2) ||
			(!params->plus_flag && params->space_flag && !negative2))
		i++;
	if (negative1 && c == '0')
		n += _putchar('-');
	if (params->plus_flag && !negative2 && c == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(c);
	if (negative1 && c == ' ')
		n += _putchar('-');
	if (params->plus_flag && !negative2 && c == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - print a number with options
 * @str: the base no. as a string
 * @params: parameter structure
 * Return: char
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, negative1, negative2, i = _strlen(str);
	char c = ' ';

	if (params->zero_flag && !params->minus_flag)
		c = '0';
	negative1 = (!params->unsign && *str == '-');
	negative2 = (!params->unsign && *str == '-');
	if (negative1 && i < params->width && c == '0' && !params->minus_flag)
		str++;
	else
		negative1 = 0;
	if (params->plus_flag && !negative2 && !params->unsign)
	{
		n += _putchar('+');
		i++;
	}
	else if (params->space_flag && !negative2 && !params->unsign)
	{
		n += _putchar(' ');
		i++;
	}
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(c);
	return (n);
}
