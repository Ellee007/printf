#include "main.h"

/**
 * handle_width - Calculates the width for printing
 * @modifier: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: width.
 */
int handle_width(va_list args, const char *modifier, char *i)
{
	int curr_i = 0;

	while ((*modifier >= '0' && *modifier <= '9') ||
		(*modifier == '*'))
	{
		(i)++;

		if (*modifier == '*')
		{
			curr_i = va_arg(args, int);
			if (curr_i <= 0)
				return (0);
			return (curr_i);

		}
		curr_i *= 10;
		curr_i += (*modifier - '0');
		modifier++;
	}
	return (curr_i);
}
