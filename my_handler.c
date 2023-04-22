#include "main.h"

/**
 * my_handler -this is a helper function for _printf
 * @format:format string
 * @index: point position
 * @arg:list of argument to be used
 * @cases: list of cases to be looped through
 * @f: the flags
 *  by victor n sue
 * @w: the width of the field
 * @p:the precision for floats
 * @s: size for our integers
 * Return: integer showing number of characters
 */
int my_handler(const char *format, int *index,
                va_list *arg, _printf_case_t *cases, int b, int c, int d, int e)
{
        int len = 0, a = 0, j = 0, option = 0;

        while (cases[j].id != format[*index] && cases[j].id)
                j++;
        if (j < 13)
        {
                option = ((j == 4)       ? BINARY_OPTION
                                  : (j == 5) ? UNSIGNED_OPTION
                                  : (j == 6) ? OCTAL_OPTION
                                  : (j == 7) ? HEX_OPTION
                                  : (j == 8) ? CAPPED_HEX_OPTION
                                  : (j == 9) ? C_STRING_OPTION
                                         : DEFAULT_OPTION);
                len += cases[j].print_case(arg, option, b, c, d, e);
        }
        if (j >= 13)
        {
                if (format[*index] == '\0')
                        return (-1);
                if (format[*index - 1] == ' ')
                        len += _putchar(' ');
                else if (c)
                {
                        *index = *index - 1;
                        while (format[*index] != ' ' && format[*index] != '%')
                                *index = *index - 1;
                        if (format[*index] == ' ')
                                *index = *index - 1;
                        return (1);
                }
                len += _putchar(format[a]);
                len += _putchar(format[a + 1]);
        }

        return (len);
}
