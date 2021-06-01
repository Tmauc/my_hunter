/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
