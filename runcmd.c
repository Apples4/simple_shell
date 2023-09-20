#include "main.h"

/**
 * run_command - run a command from an array of arguments
 * @argv: the array of arguments
 * Return: Nothing
 */

void run_command(char **argv)
{
	size_t len = 0;
	int i;
	/* checking no command was entered */
	if (argv[0] == NULL || argv[0][0] == '\0')
	{
		return;
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	len = _strlen(argv[0]);
	if (len > 0 && argv[0][len - 1] == '\n')
	{
		argv[0][len - 1] = '\0';
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			i = atoi(argv[1]);
			if (i < 1)
			{
				exit(2);
			}
			else
			{
				exit(i);
			}
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		execmd(argv);
	}
}
