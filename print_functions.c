#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * convert_char - Prints a char
 * @args: List a of arguments
 * @buffer_t: Buffer array to handle print
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
 * print_string - Prints a string
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
	unsigned int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer_t *output);
	UNUSED(flags);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (wid > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wid);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
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

	return (ren);
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

unsigned int convert_binary(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
