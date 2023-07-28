#include "main.h"

/**
 * arrange - To arrange operations for _printf.
 * @args: A va_list of arguments.
 * @output: A buffer
 */
void arrange(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * start_printf - Cross-checkformat string for _printf.
 * @format: Character string to print.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters
 */
int start_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ren = 0;
	char space;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			space = 0;
			flags = handle_flags(format + i + 1, &space);
			wid = handle_width(args, format + i +
			space + 1, &space);			
			prec = handle_precision(args, format + i + space + 1,
					&space);
			len = handle_length(format + i + space + 1, &space);

			f = handle_specifiers(format + i + space + 1);
			if (f != NULL)
			{
				i += space + 1;
				ren += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + space + 1) == '\0')
			{
				ren = -1;
				break;
			}
		}
		ren += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	arrange(args, output);
	return (ren);
}
/******************* FOR PRINTF FUNCTION ******************************/
/**
 *_printf - To display a formatted output
 *@format: To format inputs
 *Return: The characters to display
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ren;

	if (format == NULL)
	{
		return (-1);
	}
	output = init_buffer();
	if (output == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	ren = start_printf(format, args, output);
	return (ren);
}
