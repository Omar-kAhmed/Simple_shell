#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: pointer to struct info_t
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return isatty(STDIN_FILENO) && info->readfd <= STDERR_FILENO;
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char c, const char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return 1;
	return 0;
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(const char *s)
{
	int sign = 1, output = 0;
	unsigned int result = 0;
	int flag = 0;

	for (; *s && flag != 2; s++)
	{
		if (*s == '-')
			sign = -sign;
		else if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			result = result * 10 + (*s - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return output;
}
