/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_planB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:48:17 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 15:48:59 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_plan_b(t_input *input)
{
	t_stack	*current;

	current = input->b;
	while (current)
	{
		if (sum_ops(b_plan_rr(current))
			> sum_ops(b_plan_rrr(input, current))
			&& sum_ops(b_plan_rrr(input, current))
			> sum_ops(b_plan_altern(input, current)))
			current->plan = b_plan_altern(input, current);
		else if (sum_ops(b_plan_rr(current))
			> sum_ops(b_plan_rrr(input, current)))
			current->plan = b_plan_rrr(input, current);
		else
			current->plan = b_plan_rr(current);
		current = current->next;
	}
}

static t_plan	b_plan_rr(t_stack *nodeB)
{
	t_plan	plan;
	int		a;
	int		b;

	plan = (t_plan){0};
	b = nodeB->index;
	a = nodeB->target->index;
	if (a == b)
		plan.ops[RR] = a;
	else if (b > a)
	{
		plan.ops[RR] = a;
		plan.ops[RB] = b - a;
	}
	else
	{
		plan.ops[RR] = b;
		plan.ops[RA] = a - b;
	}
	return (plan);
}

static t_plan	b_plan_rrr(t_input *input, t_stack *nodeB)
{
	t_plan	plan;
	int		a;
	int		b;
	int		sizea;
	int		sizeb;

	plan = (t_plan){0};
	sizea = lst_size(input->a);
	sizeb = lst_size(input->b);
	b = nodeB->index;
	a = nodeB->target->index;
	if (sizeb - b == sizea - a)
		plan.ops[RRR] = sizeb - b;
	else if (sizeb - b > sizea - a)
	{
		plan.ops[RRR] = sizea - a;
		plan.ops[RRB] = sizeb - b - (sizea - a);
	}
	else
	{
		plan.ops[RRR] = sizeb - b;
		plan.ops[RRA] = sizea - a - (sizeb - b);
	}
	return (plan);
}

static t_plan	b_plan_altern(t_input *input, t_stack *nodeB)
{
	t_plan	plan;
	int		a;
	int		b;
	int		sizea;
	int		sizeb;

	plan = (t_plan){0};
	sizeb = lst_size(input->b);
	sizea = lst_size(input->a);
	b = nodeB->index;
	a = nodeB->target->index;
	if (b + sizea - a >= sizeb - b + a)
	{
		plan.ops[RA] = a;
		plan.ops[RRB] = sizeb - b;
	}
	else
	{
		plan.ops[RB] = b;
		plan.ops[RRA] = sizea - a;
	}
	return (plan);
}
