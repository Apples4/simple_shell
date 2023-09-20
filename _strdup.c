#include "main.h"

/**
 * _strdup - function that duplicates a string
 * @input_str: input string for suplication
 * Return: a string
 */
char *_strdup(char *input_str)
{
	char *output_dup;
	unsigned int i, j;

	if (input_str == NULL)
	{
		return (NULL);
	}
	for (i = 0; input_str[i] != '\0'; i++)
		;

	output_dup = malloc(sizeof(char *) * i + 1);
	if (output_dup == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		output_dup[j] = input_str[j];
	}
	output_dup[j] = '\0';
	return (output_dup);
}
