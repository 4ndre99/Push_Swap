/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:32:36 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 13:02:43 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_cheapest(t_input *input)
{
	t_stack	*node;
	int		i;

	update_plan_a(input);
	node = cheapest_node(input->a);
	i = node->plan.ops[RA];
	while (i--)
		ra(input);
	i = node->plan.ops[RB];
	while (i--)
		rb(input);
	i = node->plan.ops[RRA];
	while (i--)
		rra(input);
	i = node->plan.ops[RRB];
	while (i--)
		rrb(input);
	i = node->plan.ops[RR];
	while (i--)
		rr(input);
	i = node->plan.ops[RRR];
	while (i--)
		rrr(input);
	pb(input);
}

t_stack	*cheapest_node(t_stack *a)
{
	t_stack	*cheapest;

	cheapest = a;
	while (a)
	{
		if (sum_ops(cheapest->plan) > sum_ops(a->plan))
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

void	pa_cheapest(t_input *input)
{
	t_stack	*node;
	int		i;

	update_plan_b(input);
	node = cheapest_node(input->b);
	i = node->plan.ops[RA];
	while (i--)
		ra(input);
	i = node->plan.ops[RB];
	while (i--)
		rb(input);
	i = node->plan.ops[RRA];
	while (i--)
		rra(input);
	i = node->plan.ops[RRB];
	while (i--)
		rrb(input);
	i = node->plan.ops[RR];
	while (i--)
		rr(input);
	i = node->plan.ops[RRR];
	while (i--)
		rrr(input);
	pa(input);
}

void	sort_three(t_input *input)
{
	int	pos;

	pos = check_greatest(input->a)->index;
	if (pos == 0)
		ra(input);
	else if (pos == 1)
		rra(input);
	if (input->a->value > input->a->next->value)
		sa(input);
}
