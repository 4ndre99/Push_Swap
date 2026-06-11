/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:59:30 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/11 15:00:17 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_target_a(t_input *input)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = input->a;
	while (current_a)
	{
		current_b = input->b;
		current_a->target = NULL;
		while (current_b)
		{
			if (current_b->value < current_a->value
				&& (!current_a->target
					|| current_b->value > current_a->target->value))
			{
				current_a->target = current_b;
			}
			current_b = current_b->next;
		}
		if (!current_a->target)
			current_a->target = check_greatest(input->b);
		current_a = current_a->next;
	}
}

void	update_target_b(t_input *input)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_b = input->b;
	while (current_b)
	{
		current_a = input->a;
		current_b->target = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value
				&& (!current_b->target
					|| current_a->value < current_b->target->value))
			{
				current_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (!current_b->target)
			current_b->target = check_smallest(input->a);
		current_b = current_b->next;
	}
}
