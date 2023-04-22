#ifndef MAIN_H
#define MAIN_H
#define BINARY_OPTION        0
#define UNSIGNED_OPTION      1
#define OCTAL_OPTION         2
#define HEX_OPTION           3
#define CAPPED_HEX_OPTION    4
#define C_STRING_OPTION      5
#define DEFAULT_OPTION       6

#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
/**
 * struct flags - struct containing flags
 * @plus: flag for '+' character
 * @space: flag for ' ' character
 * @hash: flag for '#' character
 */
typedef struct _printf_case
{
  char id;
  int (*print_case)();
} _printf_case_t;

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);
char *convert(unsigned long int num, int base, int lowercase);
int _printf(const char *format, ...);
int (*get_print(char s))(va_list, flags_t *);
int get_flag(char s, flags_t *f);
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);
int _putchar(char c);
int _puts(char *str);
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);
int print_address(va_list l, flags_t *f);
int print_percent(va_list l, flags_t *f);
int get_width(const char *format, int *i, va_list list);
#endif
