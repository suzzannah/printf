#include "main.h"
/**
 * get_flag -This will turn on flags found by _printf
 * @s:This holds the flag specifier
 * @f: pointer to the struct flags
 * victor and sue
 * Return: 1 when flag is turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
int e = 0;
switch (s)
{
case '+':
f->plus = 1;
e = 1;
break;
case ' ':
f->space = 1;
e = 1;
break;
case '#':
f->hash = 1;
e = 1;
break;
}
return (e);
}
