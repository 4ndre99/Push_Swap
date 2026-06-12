/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:37:00 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/12 18:58:57 by ade-arau         ###   ########.fr       */
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
	else if (input->disorder == 1)
		twist_it(input);
	else if (input->strat == SIMPLE)
		sort_simple(input);
	else if (len <= 50)
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

void	sort_medium(t_input *input)
{
	int	len;
	int	cs;
	int	i;
	len = lst_size(input->a);
	cs = ft_sqrt(len);
	rank_values(input);
	sort_chunk(input, len, cs);
	i = lst_size(input->b);
	while (i--)
		biggest_to_A(input, cs);
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
