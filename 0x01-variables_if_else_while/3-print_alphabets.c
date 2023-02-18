#include <stdio.h>
/**
 * main -  main block of code
 * Description: Print the alphabets in lowercase and then in uppercase
 * followed by a new line, using 'putchar'
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

	ch = 'A';

	while (ch <= 'Z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');

	return (0);

}
