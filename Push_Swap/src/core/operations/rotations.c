/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:07:37 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 18:14:11 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	update_index(*stack);
}

void	ra(t_input *input)
{
	rotate_stack(&input->a);
	write(1, "ra\n", 3);
	input->ops_sum[RA]++;
}

void	rb(t_input *input)
{
	rotate_stack(&input->b);
	write(1, "rb\n", 3);
	input->ops_sum[RB]++;
}

void	rr(t_input *input)
{
	rotate_stack(&input->a);
	rotate_stack(&input->b);
	write(1, "rr\n", 3);
	input->ops_sum[RR]++;
}
