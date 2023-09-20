#include "main.h"

/**
 * _printf - function that prints to STDOUT
 * @argv: input streing to be printed
 * Return: char output
 */
char *_printf(char *argv)
{
	size_t x = _strlen(argv);

	write(1, argv, x);

	return (argv);
}
