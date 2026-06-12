/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:51:30 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 13:19:12 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_op(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0)
		return (1);
	return (0);
}

int	has_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
