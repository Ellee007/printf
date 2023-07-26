#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @char: for char variable
 * @int: for integer variable
 * Return: 1 or 2;
 */
unsigned int (*handle_print(const char *specifier))(va_list, buffer_t *,
	unsigned char, int, int, unsigned char)
{
	int i,

	converter_t converters[] = {
		{'c', convert_c}, {'s', convert_string},
		{'%', convert_percent}, {'i', convert_int},
		{'d', convert_di}, {'b', convert_binary},
		{'u', convert_unsigned}, {'o', convert_octal},
		{'x', convert_hexadecimal}, {'X', convert_hexa_upper},
		{'p', convert_pointer}, {'S', convert_non_printable},
		{'r', convert_reverse}, {'R', convert_rot13string},
		{'\0', NULL}};
	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
		{
			return (converters[i].func);
		}
	}
	return (NULL);
}
