#include "main.h"

/**
 * get_width - This Calculates the width for printing
 * @format: Formatted string where to print the arguments.
 * @i: List of printable arguments
 * @list: list of arguments.
 * by sue and victor
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int num_i;
	int width = 0;

	for (num_i = *i + 1; format[num_i] != '\0'; num_i++)
	{
		if (isdigit(format[num_i]))
		{
			width *= 10;
			width += format[num_i] - '0';
		}
		else if (format[num_i] == '*')
		{
			num_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = num_i - 1;

	return (width);
}
