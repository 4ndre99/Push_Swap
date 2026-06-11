/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:51:30 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/11 14:55:36 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_op(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "rr") == 0)
		return (1);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0)
		return (1);
	else if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		return (1);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0)
		return (1);
	return (0);
}