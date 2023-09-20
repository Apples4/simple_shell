#include "main.h"

/**
 * execmd - function used to execute the commands
 * @argv: input are the commands in an array pointer
 * Return: Nothing
 */
void execmd(char **argv)
{
	pid_t pid;
	char *cmd = NULL, *real_cmd = NULL;
	/* forking, duplicating the process */
	pid = fork();
	/* checking if forking failed, 0 = success */
	if (pid < 0)
	{
		perror("fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		cmd = argv[0];
		cmd_check(cmd);
		/* linking the enviroment variables for the execution */
		real_cmd = get_location(cmd);
		real_cmd_checker(real_cmd);
		if (real_cmd != NULL && execve(real_cmd, argv, environ) == -1)
		{
			perror("execve");
			if (errno == ENOENT)
			{
				perror("execve");
				free(real_cmd);
				exit(127);
			}
			else if (errno == EACCES)
			{
				perror("execve");
				free(real_cmd);
				exit(126);
			}
		}
		else
		{
			free(real_cmd);
			exit(0);
		}
	}
}

/**
 * cmd_check - a function to check cmd if its null
 * @cmd: user inpput command
 * return: Nothing
 */
void cmd_check(char *cmd)
{
	if (cmd == NULL)
	{
		perror("empty command");
		exit(2);
	}
}

/**
 * real_cmd_checker - a function to check real_cmd
 * @cmd: Full path of the command
 * Return: Nothing
 */
void real_cmd_checker(char *cmd)
{
	if (cmd == NULL)
	{
		perror("command not found");
		exit(127);
	}
}

