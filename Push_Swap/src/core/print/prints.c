/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:38:01 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/11 14:35:39 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printint(int c)
{
	long	n;
	int		count;

	n = (long)c;
	count = 0;
	if (n < 0)
	{
		count += printchar('-');
		n = -n;
	}
	if (n >= 10)
		count += printint(n / 10);
	count += printchar((n % 10) + '0');
	return (count);
}
