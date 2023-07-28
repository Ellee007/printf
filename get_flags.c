#include "main.h"

/**
 * handle_flags - Calculates active flags
 * @flag: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
unsigned char handle_flags(const char *flag, char *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	unsigned char ren = 0;
	flag_t flags[] = {
		{'-', NEG},
		{'+', PLUS},
		{'0', ZERO},
		{'#', HASH},
		{' ', SPACE},
		{0, 0}
		};

	for (curr_i = *i + 1; flag[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; flags[j].flag != '\0'; j++)
			if (flag[curr_i] == flags[j].flag)
			{
				(*i)++;
				if (ren == 0)
					ren = flags[j].value;
				else
					ren |= flags[j].value;
				break;
			}

		if (flags[j].value == 0)
			break;
	}

	return (ren);
}
