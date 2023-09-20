#include "main.h"
/**
 * main - entry point
 * Return: 0 for successs
 */
int main(void)
{
	char *cmd = NULL, *cmd_copy = NULL, *delim = " \n";
	size_t n = 0, len = 0;
	int argc = 0, getline_out = 0, terminal  = isatty(0), status;
	char **argv = NULL;
	/* loop to keep function in prompt */
	while (1)
	{
		if (terminal == 1)
			_printf("($) ");
		getline_out = getline(&cmd, &n, stdin);
		if (getline_out == -1)
		{
			free(cmd);
		/*	_printf("\n");*/
			exit(0);
		}
		if (cmd[0] == '\0')
		{
			_printf("\n");
			continue;
		}
		cmd_copy = _strdup(cmd);
		if (cmd_copy == NULL)
		{
			perror("strdup cmd_copy");
			exit(1);
			free(cmd);
		}
		len = _strlen(cmd_copy);
		if (len > 0 && cmd_copy[len - 1] == '\n')
			cmd_copy[len - 1] = '\0';
		argc = get_argc(cmd, delim);
		argv = get_argv(cmd_copy, delim, argc);
		run_command(argv);
		free(cmd_copy);
		free(argv);
		wait(&status);
	}
	free(cmd);
	return (0);
}

/**
 * get_argc - get the number of arguments from a command
 * @cmd: the command string
 * @delim: the delimiter string
 * Return: the number of arguments
 */

int get_argc(char *cmd, char *delim)
{
	int argc = 0;
	char *token = NULL;

	token = strtok(cmd, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	return (argc);
}

/**
 * get_argv - get the array of arguments from a command copy
 * @cmd_copy: the command copy string
 * @delim: the delimiter string
 * @argc: the number of arguments
 * Return: the array of arguments
 */

char **get_argv(char *cmd_copy, char *delim, int argc)
{
	char **argv;
	char *token = NULL;
	int i = 0;
	size_t cmd_len = 0;

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		perror("malloc argv");
		exit(1);
	}
	cmd_len = _strlen(cmd_copy);
	if (cmd_len > 0 && cmd_copy[cmd_len - 1] == '\n')
	{
		cmd_copy[cmd_len - 1] = '\0';
	}
	/* put tokens of command input into an array */
	token = strtok(cmd_copy, delim);
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
