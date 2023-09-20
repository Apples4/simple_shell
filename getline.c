#include "main.h"

/**
 * getout - function to use the getline
 * Return: a char pointer is returned
 */
char *getout(void)
{
	char *buffer = NULL;
	size_t n = 0;

	getline(&buffer, &n, stdin);
	return (buffer);
}
