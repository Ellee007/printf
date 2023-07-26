#include "main.h"

/**
 * handle_length - Calculates the size to cast the argument
 * @modifier: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
unsigned char handle_length(const char *modifier, char *i)
{
	if (*modifier == '1')
	{
		(*i)++;
		return (LONG);
	}
	else if (*modifier == 'h')
	{
		(*i)++;
		return (SHORT);
	}
	return (0);
}
