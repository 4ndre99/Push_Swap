/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:20:25 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/09 15:51:47 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	printfloat(double c)
{
	static int	res;
	char		a;

	res = c * 100;
	a = (res / 1000) + 48;
	write(1, &a, 1);
	a = (res / 100) % 10 + 48;
	write(1, &a, 1);
	write(1, ".", 1);
	a = ((res / 10) % 10) + 48;
	write(1, &a, 1);
	a = res % 10 + 48;
	write(1, &a, 1);
	write(1, "%", 1);
	return (6);
}

static int	organizer(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += printchar(va_arg(args, int));
	if (type == 's')
		count += printstr(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += printint(va_arg(args, int));
	if (type == '%')
		count += printchar('%');
	if (type == 'f')
		count += printfloat(va_arg(args, double));
	return (count);
}

int	print(const char *content, ...)
{
	va_list	al;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(al, content);
	while (content[i])
	{
		if (content[i] == '%')
		{
			i++;
			if (!content[i])
				return (-1);
			count += organizer(content[i], al);
		}
		else
			count += printchar(content[i]);
		i++;
	}
	va_end(al);
	return (count);
}
