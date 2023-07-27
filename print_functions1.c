#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

unsigned int convert_unsignd(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);i
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_octal(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************** To PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Names or Number of arguments
 * @buffer: Container array to hold print
 * @flags:  Calculates flags that are active
 * @width: To get width length
 * @precision: Precise Definitions
 * @size: Size specifier
 * Return: The hexadecimal number
 */
unsigned int convert_hexadecimal(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_hexa_upper(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);i
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** TO PRINT HEXA NUMS IN LOW OR UPPER CASE **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: Lista of arguments
 * @output: Array of values for buffer  number
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specification
 * Return: Number of chars printed
 */
unsigned int convert_pointer(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);i
{
	char *nul = "(nil)";
	unsigned long int num;
	unsigned int ren = 0;

	(void)len;
	
	num = va_arg(args, unsigned long int);
	if (num == '\0')
	{
		return (_memcpy(output, nul, 5));
	}
	flags |= 32;
	ren += convert_ubase(output, address, "0123456789abcdef", flags
			wid, prec);
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}
