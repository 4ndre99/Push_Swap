/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_planA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:42:39 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/09 18:18:55 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_plan	a_plan_rr(t_stack *stackA)
{
	t_plan	plan;
	int		a;
	int		b;

	plan = (t_plan){0};
	a = stackA->index;
	b = stackA->target->index;
	if (a == b)
		plan.ops[RR] = a;
	else if (a > b)
	{
		plan.ops[RR] = b;
		plan.ops[RA] = a - b;
	}
	else
	{
		plan.ops[RR] = a;
		plan.ops[RB] = b - a;
	}
	return (plan);
}

static t_plan	a_plan_rrr(t_input *input, t_stack *nodeA)
{
	t_plan	plan;
	int		a;
	int		b;
	int		sizea;
	int		sizeb;

	plan = (t_plan){0};
	sizea = lst_size(input->a);
	sizeb = lst_size(input->b);
	a = nodeA->index;
	b = nodeA->target->index;
	if (a == b)
		plan.ops[RRR] = sizea - a;
	else if (sizea - a > sizeb - b)
	{
		plan.ops[RRR] = sizeb - b;
		plan.ops[RRA] = sizea - a - (sizeb - b);
	}
	else
	{
		plan.ops[RRR] = sizea - a;
		plan.ops[RRB] = sizeb - b - (sizea - a);
	}
	return (plan);
}

static t_plan	a_plan_altern(t_input *input, t_stack *nodeA)
{
	t_plan	plan;
	int		a;
	int		b;
	int		sizea;
	int		sizeb;

	plan = (t_plan){0};
	sizea = lst_size(input->a);
	sizeb = lst_size(input->b);
	a = nodeA->index;
	b = nodeA->target->index;
	if (a + sizeb - b >= sizea - a + b)
	{
		plan.ops[RB] = b;
		plan.ops[RRA] = sizea - a;
	}
	else
	{
		plan.ops[RA] = a;
		plan.ops[RRB] = sizeb - b;
	}
	return (plan);
}

void	update_plan_a(t_input *input)
{
	t_stack	*current;

	current = input->a;
	while (current)
	{
		if (sum_ops(a_plan_rr(current))
			> sum_ops(a_plan_rrr(input, current))
			&& sum_ops(a_plan_rrr(input, current))
			> sum_ops(a_plan_altern(input, current)))
			current->plan = a_plan_altern(input, current);
		else if (sum_ops(a_plan_rr(current))
			> sum_ops(a_plan_rrr(input, current)))
			current->plan = a_plan_rrr(input, current);
		else
			current->plan = a_plan_rr(current);
		current = current->next;
	}
}
