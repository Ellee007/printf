#include "main.h"

/**
 *_memcpy - To moves bytes from src to struct output
 *@output: Struct to move buffer
 *@src: pointer to memeroy
 *@m: The number of bytes moved
 *
 *Return: The number of bytes needed to be moved
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int m)
{
	unsigned int ind;

	for (ind = 0; ind < m; ind++)
	{
		*(output->buffer) = *(src + ind);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
		{
			(output->buffer)++;
		}
	}
	return (m);
}
/**
 *init_buffer -To initialize buffer for struct
 *
 *Return: To return the address to pointer
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));

	if (output == NULL)
	{
		return (NULL);
	}
	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}
	output->start = output->buffer;
	output->len = 0;

	return (output);
}
/**
 *free_buffer - To free the buffer
 *
 *@output:The buffer to be free
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}
