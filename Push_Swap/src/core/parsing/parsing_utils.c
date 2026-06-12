/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:47:41 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/12 12:48:30 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	valid_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& str[i + 1]
		&& (str[i + 1] >= '0' || str[i + 1] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(t_stack *a)
{
	t_stack	*j;

	if (!a)
		return (0);
	while (a)
	{
		j = a->next;
		while (j)
		{
			if (a->value == j->value)
				return (0);
			j = j->next;
		}
		a = a->next;
	}
	return (1);
}

void	free_split(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg[i])
		i++;
	while (i >= 0)
		free(arg[i--]);
	free(arg);
}

int	parse_argument(t_stack **a, char *str)
{
	int		i;
	char	**arg;

	arg = ft_split(str, ' ');
	if (!arg || !*arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!valid_num(arg[i]))
			return (free_split(arg), 0);
		if (ft_atoi(arg[i]) == 0 && ft_strlen(arg[i]) > 2)
			return (0);
		lst_addback(a, ft_atoi(arg[i]));
		i++;
	}
	return (free_split(arg), 1);
}

int	parsing(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
		i++;
	while (argv[i])
	{
		if (!parse_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (check_dups(*a));
}
