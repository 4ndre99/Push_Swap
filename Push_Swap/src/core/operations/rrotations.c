/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:11:32 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 18:15:01 by ade-arau         ###   ########.fr       */
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
	last->next = first;
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
