/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:47:41 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/10 15:32:58 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dups(t_input *input)
{
	t_stack	*i;
	t_stack	*j;
	
	i = input->a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
void	free_split(char **arg)
{
	int	i;

	if (!arg || !*arg)
		return ;
	i = 0;
	while (arg[i])
		i++;
	while (i >= 0)
		free(arg[i--]);
}

int	parse_argument(t_input *input, char *str)
{
	int	i;
	char	**arg;

	arg = ft_split(str, ' ');
	if (!arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!valid_num(arg[i]))
			return (free_split(arg), 0);
		lst_addback(input, ft_atoi(arg[i]));
		i++;
	}
	return (free_split(arg), 1);
}
