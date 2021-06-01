/*
** EPITECH PROJECT, 2017
** stdarg
** File description:
** 
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

void waprint(char format, va_list list)
{
	switch (format) {
	case 'i':
	case 'd':
		my_put_nbr(va_arg(list, int));
		break;
	case 'c':
		my_putchar(va_arg(list, int));
		break;
	case 's':
		my_putstr(va_arg(list, char*));
		break;
	case 'u':
		my_put_nbr(va_arg(list, unsigned int));
		break;
	}
}

int my_printf(char *format, ...)
{
	va_list list;
	int i = 0;

	va_start(list, format);
	while (format[i] != '\0') {
		if (format[i] == '%') {
			i++;
			if (format[i] =='%') {
				my_putchar(format[i]);
				i++;
			} else {
				waprint(format[i], list);
				i++;
			}
		} else {
			my_putchar(format[i]);
			i++;
		}
	}
	va_end(list);
	return (0);
}
