/*
** EPITECH PROJECT, 2017
** randnum
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randnum()
{
	int nbgen = rand() % 555 + 0;
	return (nbgen);
}
