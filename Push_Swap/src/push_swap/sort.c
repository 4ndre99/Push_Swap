/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:37:00 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/11 15:47:16 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_input *input)
{
	int	len;

	update_index(input->a);
	len = lst_size(input->a);
	if (len == 2)
		sa(input);
	else if (len == 3)
		sort_three(input);
	else if (input->strat == SIMPLE)
		sort_simple(input);
	else if (input->strat == MEDIUM)
		sort_medium(input);
	else if (input->strat == COMPLEX)
		sort_complex(input);
	else if (input->strat == ADAPTIVE)
		sort_adaptive(input);
}

void	sort_simple(t_input *input)
{
	int	size;
	int	index;

	size = lst_size(input->a);
	while (size > 1)
	{
		index = (check_smallest(input->a))->index;
		if (index <= size / 2 && index > 0)
		{
			while (index--)
				ra(input);
		}
		else if (index > size / 2)
		{
			index = size - index;
			while (index--)
				rra(input);
		}
		pb(input);
		size--;
	}
	while (input->b)
		pa(input);
}

void	sort_medium(t_input *input)
{
	if (lst_size(input->a) > 4)
		pb(input);
	pb(input);
	while (lst_size(input->a) > 3)
	{
		update_target_a(input);
		pb_cheapest(input);
	}
	if (!is_sorted(input->a))
		sort_three(input);
	while (lst_size(input->b))
	{
		update_target_b(input);
		pa_cheapest(input);
	}
	lowest_to_top(input);
}

void	sort_complex(t_input *input)
{
	rank_values(input);
	sort_radix(input);
}

void	sort_adaptive(t_input *input)
{
	double	dis;

	dis = input->disorder;
	if (dis < 0.2)
		sort_simple(input);
	else if (dis >= 0.2 && dis < 0.5)
		sort_medium(input);
	else
		sort_complex(input);
}
