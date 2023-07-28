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
 * convert_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: Names or Number of arguments
 * @output: Container array to hold print
 * @flags:  Calculates flags that are active
 * @wid: To get width length
 * @prec: Precise Definitions
 * @len: Size specifier
 * Return: The hexadecimal number
 */
unsigned int convert_hexadecimal(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
{
	char *top = "0x";
	unsigned int ren = 0;
	unsigned long int digit;
	
	if (len == LONG)
	{
		digit = va_arg(args, unsigned long int);
	}
	else
		digit = va_arg(args, unsigned int);
	
	if (len == SHORT)
	{
		digit = (unsigned short)digit;
	}
	if (HASH_FLAG == 1 && != 0)
	{
		ren += _memcpy(output, top, 2);
	}
	if (!(digit == 0 && prec == 0))
	{
		ren += convert_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}

/**
 * convert_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @output: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wid: get width
 * @prec: Precision specification
 * @len: Size specifier
 * Return: Number of chars printed
 */
unsigned int convert_hexa_upper(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);i
{
	char *top = "0X";
	unsigned long int digit;
	unsigned int ren = 0;

	if (len == LONG)
	{
		digit = va_args(args, unsigned long);
	}
	else
	{
		digit = va_arg(args, unsigned int);
	}
	if (len == SHORT)
	{
		digit = (unsigned short)digit;
	}
	if (HASH_FLAG == ! && digit != 0)
		ren += _memcpy(output, top,, 2);
	if (!(digit == 0 && prec == 0)
	{
		ren += conver_ubase(output, digit, "0123456789ABCDEF",
				flags, wid, prec);
	}
	ren += print_neg_width(output, ren, flags, wid);
	return (ren);
}

/************** TO PRINT HEXA NUMS IN LOW OR UPPER CASE **************/
/**
 * convert_pointer - Prints a hexadecimal number in lower or upper
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
