/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:12:14 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 18:15:40 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	update_index(*stack);
}

void	sa(t_input *input)
{
	swap_stack(&input->a);
	write(1, "sa\n", 3);
	input->ops_sum[SA]++;
}

void	sb(t_input *input)
{
	swap_stack(&input->b);
	write(1, "sb\n", 3);
	input->ops_sum[SB]++;
}

void	ss(t_input *input)
{
	swap_stack(&input->a);
	swap_stack(&input->b);
	write(1, "ss\n", 3);
	input->ops_sum[SS]++;
}
