#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - to read text files
 *
 * @filename: a character pointer
 *
 * @letters: prints letters
 *
 * Return: when successful
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor, read_bytes, written_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = (char *)malloc(sizeof(char) * letters);
	if (buffer == NULL)
	return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		free(buffer);
		return (0);
	}

	read_bytes = read(file_descriptor, buffer, letters);
	if (read_bytes == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	written_bytes = write(STDOUT_FILENO, buffer, read_bytes);
	if (written_bytes == -1 || written_bytes != read_bytes)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);
	return (written_bytes);
}
