/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twist_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:03:22 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 13:06:56 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twist_it(t_input *in)
{
	int	len_a;
	int	len_b;

	len_a = lst_size(in->a);
	while (len_a > 1)
	{
		rra(in);
		pb(in);
		len_a--;
	}
	len_b = lst_size(in->b);
	while (len_b--)
		pa(in);
}