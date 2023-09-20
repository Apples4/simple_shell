#include "main.h"

/**
 * _strcat - Function that combines two char types
 * @dest: initial input of char type
 * @src: second input of char type
 * Return: Combined char types
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	char *y = dest;
	char *z = src;

	while (y[i] != '\0')
	{
		i++;
	}

	while (z[j] != '\0')
	{
		y[i] = src[j]; /* combining arrays */
		j++;
		i++;
	}

	y[i] = '\0';
	return (y);
}
