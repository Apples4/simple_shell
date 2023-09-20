#include "main.h"

/**
 * trim - Remove leading and trailing white spaces from a string
 * @str: The input string
 * Return: A pointer to the trimmed string
 */
char *trim(char *str)
{
	char *end;

	while (isspace(*str))
		str++;

	if (*str == 0)
		return (str);

	end = str + _strlen(str) - 1;
	while (end > str && isspace(*end))
		end--;

	*(end + +1) = '\0';

	return (str);
}
