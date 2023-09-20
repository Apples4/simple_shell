#ifndef _MAIN_H_
#define _MAIN_H_

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <ctype.h>
#include <errno.h>

/* functions */
extern char **environ;
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void execmd(char **argv);
char *get_location(char *command);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_printf(char *argv);
int _str_len(char **s);
char **get_argv(char *cmd_copy, char *delim, int argc);
int get_argc(char *cmd, char *delim);
char *get_location(char *cmd);
char *_strman(char *file_path, char *path_token, char *cmd);
char *_strdup(char *input_str);
char *getout(void);
void run_command(char **argv);
char *trim(char *str);
void cmd_check(char *cmd);
void real_cmd_checker(char *cmd);
void print_env(void);
#endif
