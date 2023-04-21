#include "main.h"

/**
 * _printf -> This Prints a formatted string
 * c
 * @format:this Inputs the String Format
 *
 * Return: Number of chars Printed
 */

int _printf(const char *format, ...)
{
	int printed = 0, k;
	va_list list;

	va_start(list, format);
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] == '%')
		{
			k++;
			if (format[k] == 'c')
				printed += _put(va_arg(list, int));
			else if (format[k] == 's')
				printed += _puts(va_arg(list, char *));
			else if (format[k] == 'd' || format[k] == 'k')
				printed += put_int(va_arg(list, int));
			else if (format[k] == 'b')
				printed += put_binary(va_arg(list, unsigned int));
			else
				printed += _put(format[k]);
		} else
			printed += _put(format[k]);
	} va_end(list);
	return (printed);
}
