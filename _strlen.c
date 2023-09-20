#include "main.h"

/**
* _strlen - provides the length of a string
* @s: char input into a function
* Return: A output will be a integer
*/

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
