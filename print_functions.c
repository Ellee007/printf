#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * convert_char - Prints a char
 * @args: List a of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: Width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printe
 */
unsigned int convert_char(va_list args, buffer_t *display,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char c = va_arg(args, int);
	unsigned int ren = 0;

	(void)prec;
	(void)len;

	return (handle_write_char(c, buffer_t *output, flags, wid, prec, len));
	ren += _memcpy(display, &c, 1);
	ren += print_width(output, ren, flags, wid);
	ren += print_neg_width(output, ren, flags, wid);

	return (ren);
}
/************************* PRINT A STRING *************************/
/**
 * pconvert_string - Prints a string
 * @args: List a of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_string(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	int count;
	unsigned int ren = 0;
	char *str, *null = "(null)";

	(void)len;
	(void)flags;
	
	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (_memcpy(output, null, 6));
	}
	for (size = 0; *(str + count);)
		count++;
	ren += print_string_width(output, flags, wid, prec, size);
	prec = (prec == -1) ? count : prec;
	while (*str != '\0' && prec > 0)
	{
		ren += _memcpy(output, str, 1);
		prec--;
		str++;
	}
	ren += print_neg_width(output, ren, flags, wid);

	return (ren);
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * convert_percent - Prints a percent sign
 * @args: Lista of arguments
 * @otput: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_percent(va_list args, char buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int ren = 0;

	(void)args;
	(void)prec;
	(void)len;

	ren += print_width(output, ren, flags, wid);
	ren += _memcpy(output, &percent, 1);
	ren += print_neg_width(output, ren, flags, wid);

	return (ren);`
}

/************************* PRINT INT *************************/
/**
 * convert_di - Print int
 * @srgs: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
{
	char pad, space = ' ', neg = '-', plus = '+';
	long int n, rep;
	unsigned int ren = 0, num = 0;

	if (len == LONG)
		n = va_arg(args, long int);
	else
		n = va_arg(args, int);
	if (len == SHORT)
		n = (short)n;
	if (SPACE_FLAG == 1 && d >= 0)
		ren += _memcpy(output, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0)
	{
		if (n == LONG_MIN)
		{
			num += 19;
		}
		else
		{
			for (rep = (n < 0) ? -n : n; rep > 0; rep /= 10)
				num++;
		}
		num += (n == 0) ? 1 : 0;
		num += (n < 0) ? 1 : 0;
		num += (PLUS_FLAG == 1 && n >= 0) ? 1 : 0;
		num += (SPACE_FLAG == 1 && n >= 0) ? 1 : 0;

		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && n >= 0)
			ren += _memcpy(output, &plus, 1);
		if (ZERO_FLAG == 1 && n < 0)
		{
			ren += _memcpy(output, &neg, 1);
		}
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= num; wid > 0; wid--)
		{
			ren += _memcpy(output, &pad, 1);
		}
	}
	if (ZERO_FLAG == 0 && n < 0)
	{
		ren += _memcpy(output, &neg, 1);
	}
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && n >= 0))
	{
		ren += _memcpy(output, &plus, 1);
	}
	if (!(n == 0 && prec == 0))
	{
		ren += convert_sbase(output, d, "0123456789",
				flags, 0, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
/************************* PRINT BINARY *************************/
/**
 * convert_binary - Prints an unsigned number
 * @args: Lista of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width.
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Numbers of char printed.
 */

unsigned int convert_binary(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
{
	unsigned int sum;
	
	sum = va_arg(args, unsigned int);
	(void)len;

	return (convert_ubase(output, sum, "01", flags, wid, prec));
}
