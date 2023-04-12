#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - creates a new file
 *
 * @filename: a constant char pointer
 *
 * @text_content: a char pointer
 *
 * Return: when successful
 */
int create_file(const char *filename, char *text_content)
{
	int file_decripter;

	if (filename == NULL)
	{
		return (-1);
	}

	file_decripter = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (file_decripter == -1)
	{
		perror("open");
		return (-1);
	}
	if (text_content != NULL)
	{
		size_t lenght = strlen(text_content);

		ssize_t num_written = write(file_decripter, text_content, lenght);

		if (num_written == -1)
		{
			perror("write");
			close(file_decripter);
			return (-1);
		}
		if ((size_t) num_written != lenght)
		{
			fprintf(stderr, "write: partial write\n");
			close(file_decripter);
			return (-1);
		}
	}
	close(file_decripter);
	return (1);
}
