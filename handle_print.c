#include "main.h"
/**
 * handle_specifiers - Prints an argument based on its type
 * @*: for integer variable
 * @char: for char variable
 * @int: for number
 * Return: 1 or 2;
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
	unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convert_char},
		{'s', convert_string},
		{'%', convert_percent},
		{'i', convert_di},
		{'d', convert_di},
		{'b', convert_binary},
		{'u', convert_unsigned},
		{'o', convert_octal},
		{'x', convert_hexadecimal},
		{'X', convert_hexa_upper},
		{'p', convert_pointer},
		{'S', convert_non_printable},
		{'r', convert_reverse},
		{'R', convert_rot13string},
		{'\0', NULL}

	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
		{
			return (converters[i].func);
		}
	}
	return (NULL);
}
