#include "main.h"

/**
 * print_char - print character
 * @ap: argument
 * @params: parameter structure
 * Return: number of printed characters
 */

int print_char(va_list ap, params_t *params)
{
	char c = ' ';
	unsigned int x = 1, sum = 0, y = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(y);
	while (x++ < params->width)
		sum += _putchar(c);
	if (!params->minus_flag)
		sum += _putchar(y);
	return (sum);
}

/**
 * print_int - print integer
 * @ap: argument
 * @params: parameter structure
 * Return: no. of printed characters
 */

int print_int(va_list ap, params_t *params)
{
	long x;

	if (params->l_modifier)
		x = va_arg(ap, long);
	else if (params->h_modifier)
		x = (short int)va_arg(ap, int);
	else
		x = (int)va_arg(ap, int);
	return (print_number(convert(x, 10, 0, params), params));
}

/**
 * print_string - print string
 * @ap: argument
 * @params: parameter structure
 * Return: no. of printed characters
 */

int print_string(va_list ap, params_t *params)
{
	char *string = va_arg(ap, char *), c = ' ';
	unsigned int x, sum = 0, i, j;
	(void)params;

	switch ((int)(!string))
		case 1:
			string = NULL_STRING;
	j = _strlen(string);
	x = _strlen(string);
	if (params->precision < x)
	{
		j = params->precision;
		x = params->precision;
	}
	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < x; i++)
				sum += _putchar(*string++);
		}
		else
			sum += _puts(string);
	}
	while (j++ < params->width)
		sum += _putchar(c);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < x; i++)
				sum += _putchar(*string++);
		}
		else
			sum += _puts(string);
	}
	return (sum);
}

/**
 * print_percent - print string
 * @ap: argument
 * @params: parameter structure
 * Return: no. of printed characters
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	return (_putchar('%'));
}

/**
 * print_S - format specifier
 * @ap: argument
 * @params: parameter structure
 * Return: no. of printed characters
 */

int print_S(va_list ap, params_t *params)
{
	char *string = va_arg(ap, char *), *hex;
	int sum = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	while (*string)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*string, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*string);
		string++;
	}
	return (sum);
}
