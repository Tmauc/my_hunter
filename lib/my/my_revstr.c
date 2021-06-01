/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** my_revstr.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
	int i = 0;
	int len = my_strlen(str);
	char c;

	while (i < len / 2) {
		c = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = c;
		i = i + 1;
	}
	return (str);
}
