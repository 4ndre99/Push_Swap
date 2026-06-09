/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:11:32 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/01 16:23:14 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	update_index(*stack);
}

void	rra(t_input *input)
{
	reverse_rotate_stack(&input->a);
	write(1, "rra\n", 4);
	input->ops_sum[RRA]++;
}

void	rrb(t_input *input)
{
	reverse_rotate_stack(&input->b);
	write(1, "rrb\n", 4);
	input->ops_sum[RRB]++;
}

void	rrr(t_input *input)
{
	reverse_rotate_stack(&input->a);
	reverse_rotate_stack(&input->b);
	write(1, "rrr\n", 4);
	input->ops_sum[RRR]++;
}
