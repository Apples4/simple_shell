#include "main.h"
/**
 * get_location - a function to get the file path of for a command
 * @cmd: input command by the user
 * Return: pointer of the path enviroment
 */
char *get_location(char *cmd)
{
	char *path, *path_copy;
	int cmd_length = 0, directory_length = 0;
	char *path_token, *file_path;
	char *delim = ":";
	struct stat buf;
	/* set path to enviroment variables */
	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		cmd_length = _strlen(cmd);
		path_token = strtok(path_copy, delim);
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(cmd_length + directory_length + 2);
			if (file_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			_strman(file_path, path_token, cmd);
			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, delim);
			}
		}
		free(path_copy);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
	}
	return (NULL);
}

/**
 * _strman - manipulates the strings path for enviroment
 * @file_path: an input path
 * @path_token: an input that for enviroments
 * @cmd: input command
 * Return: a pointer to a file path
 */
char *_strman(char *file_path, char *path_token, char *cmd)
{
	if (file_path == NULL || path_token == NULL || cmd == NULL)
		return (NULL);
	_strcpy(file_path, path_token);
	_strcat(file_path, "/");
	_strcat(file_path, cmd);

	return (file_path);
}
