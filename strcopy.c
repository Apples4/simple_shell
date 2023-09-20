#include "main.h"

/**
 * *_strcpy - a function that copies a string pointer at a variable
 * @dest: variable
 * @src: char variable
 * Return: A char value
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
