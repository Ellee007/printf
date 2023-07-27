#include "main.h"

/*****************************CONVERT A SIGNED LONG *************************/

/**
 * convert_sbase - Converts a signed long to an inputted base and stores
 * the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int count;
	char number, pad = '0';
	unsigned int ren = 1;

	for (count = 0; *(base + count);)
		count++;

	if (num >= count || num <= -count)
		ren += convert_sbase(output, num / count, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--) /* Handle for prec */
			ren += _memcpy(output, &pad, 1);
		if (NEG_FLAG == 0) 
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ren += _memcpy(output, &pad, 1);
		}
	}

	number = base[(num < 0 ? -1 : 1) * (num % count)];
	_memcpy(output, &digit, 1);

	return (ren);
}
/*************************** CONVERT _UNSIGNED LONG ************************/
/**
 * convert_ubase - Converts an unsigned long to an inputted base and
 * stores the result to a buffer..
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag specifiers.
 * @wid: A width specifier.
 * @prec: A precision specifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int count, ren = 1;
	char number, pad = '0', *top = "0x";

	for (count = 0; *(base + count);)
		count++;

	if (num >= count)
		ren += convert_ubase(output, num / count, base,
				flags, wid - 1, prec - 1);

	else
	{
		if (((flags >> 5) & 1) == 1) 
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--)
			ren += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ren += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1)
			ren += _memcpy(output, *top, 2);
	}

	number = base[(num % count)];
	_memcpy(output, &number, 1);

	return (ren);
}
