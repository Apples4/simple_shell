#include "main.h"

/**
 * print_env - prints the current enviroment
 * Return: Nothing
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}
