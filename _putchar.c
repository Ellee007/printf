#include "main.h"
#include <unistd.h>

/**
 * _putchar - Prints a character
 * @c: Character to display
 * Return: 1 if successful
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
