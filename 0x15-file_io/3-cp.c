#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - main  function
 * @argc: integer
 * @argv: char pointer
 * Return: when successful
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_bytes_read, num_bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((num_bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		num_bytes_written = write(fd_to, buffer, num_bytes_read);
		if (num_bytes_written == -1)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (num_bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fd_from) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
	fprintf(stderr, "Error: Can't close fd %d\n", fd_to);
	exit(100);
	}
	return (0);
}
