#include "main.h"

/**
 * _strcmp - a function that compares strings
 * @s1: initial string input
 * @s2: second string input
 * Return: A integer
 */
int _strcmp(char *s1, char *s2)
{
	int sum = 0, x = 0;

	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
	{
		x++;
	}
	sum = s1[x] - s2[x];
	return (sum);
}
