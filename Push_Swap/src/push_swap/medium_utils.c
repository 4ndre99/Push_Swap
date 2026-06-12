/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:50:27 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 19:21:44 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(int nb, int i)
{
	if ((i * i) == nb)
		return (i);
	if ((i * i) > nb)
		return (i);
	return (compare(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 1)
		return (0);
	return (compare(nb, 1));
}

static int	closest_to_top(t_stack *a, int len, int cap)
{
	t_stack	*closest;
	int		ops;
	int		ops_prev;

	closest = NULL;
	ops_prev = INT_MAX;
	while (a)
	{
		if (a->index <= len / 2)
			ops = a->index;
		else
			ops = len - a->index;
		if (a->value < cap && ops < ops_prev)
		{
			closest = a;
			ops_prev = ops;
		}
		a = a->next;
	}
	if (closest->index <= len / 2)
		return (0);
	else
		return (1);
}
	
void	sort_chunk(t_input *in, int len, int cs)
{
	int chunks;
	int i;
	int	j;

	i = 0;
	chunks = len / cs;
	while (++i <= chunks)
	{
		j = -1;
		while (++j < cs)
		{
			while (in->a->value >= i * cs)
			{
				if (closest_to_top(in->a, len, i * cs))
					rra(in);
				else
					ra(in);
			}
			pb(in);
		}
	}
	while (in->a)
		pb(in);
}

void	biggest_to_A(t_input *in, int cs)
{
	t_stack *b;
	int		max;
	int		max_index;
	int		i;

	b = in->b;
	max_index = -1;
	max = -1;
	i = -1;
	while (b && ++i <= cs)
	{
		if (b->value > max)
		{
			max_index = b->index;
			max = b->value;
		}
		b = b->next;
	}
	i = -1;
	if (max_index == 1)
		sb(in);
	while (++i < max_index && max_index > 1)
		rb(in);
	pa(in);
	while (i--)
		rrb(in);
}