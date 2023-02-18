#include <stdio.h>

/**
 * main - Print the alphabets in lowercase with 'putchar'
 *
 * Return: 0
*/

int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');

	return (0);

}
