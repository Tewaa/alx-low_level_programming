#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * append_text_to_file - to append the new text
 *
 * @filename: a char pointer
 *
 * @text_content: a char pointer
 *
 * Return: when successful
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;

	ssize_t num_written;

	if (filename == NULL)
	{
		return (-1);
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		size_t length = 0;

		while (text_content[length] != '\0')
		{
			length++;
		}
		num_written = write(file_descriptor, text_content, length);

		if (num_written == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}
