#include "main.h"

/****************** THIS IS TO PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2,
	for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * convert_non_printable - Prints ascii codes in hexa of non printable chars
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_non_printable(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	int count, ind;
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	unsigned int ren = 0;
	
	(void)len;

	if (str == NULL)
		return (_memcpy(output, null, 6));
	
	for (count = 0; str[count];)
		count++;
	ren += print_string_width(output, flags, wid, prec, count);

	prec = (prec == -1) ? count : prec;
	for (ind = 0; *(str + ind) != '\0' && ind < prec; ind++)
	{
		if (*(str + ind) < 32 || *(str + ind) >= 127)
		{
			ren += _memcpy(output, hex, 2);
			if (*(str +ind) < 16)
			{
				ren += _memcpy(output, &zero, 1);
			}
			ren += convert_ubase(output, *(str + ind),
					"0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ren += _memcpy(output, (str + ind), 1);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************************* PRINT REVERSE *************************/
/**
 * convert_reverse - Prints reverse string.
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of chars printed
 */

unsigned int convert_reverse(va_list args, buffer *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int i, count, end;
	unsigned int ren = 0

	(void)flags;
	(void)len;

	str = va_arg(types, char *);

	if (str == NULL)
	{
		return (_memcpy(output, null, 6));
	}
	for (count = 0; *(str + size);)
		count++;
	ren += print_string_width(output, flags, wid, prec, count);
	end = count - 1;
	prec = (prec == -1) ? count : prec;

	for (i = 0; end >= 0 && i < prec; i++)
	{
		ren += _memcpy(output, (str + end), 1);
		end--;
	}

	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * convert_rot13string - Print a string in rot13.
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of chars printed
 */
unsigned int convert_rot13string(va_list args, buffer *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *nul = "(null)";
	unsigned int ren = 0;
	int i, j, count;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	str = va_arg(args, char *);
	
	if (str == NULL)
		return (_memcpy(output, null, 6));
	for (count = 0; *(str + count);)
		count++;
	ren += print_string_width(output, flags, wid, prec, len);
	
	prec = (prec == -1) ? count : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ren += _memcpy(output, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
		{
			ren += _memcpy(output, (str + i), 1);
		}
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
