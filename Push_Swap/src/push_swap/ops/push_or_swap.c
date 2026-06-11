/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:21:19 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/11 14:22:21 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pa(t_input *input)
{
	push_stack(&input->b, &input->a);
	write(1, "pa\n", 3);
	input->ops_sum[PA]++;
}

void	pb(t_input *input)
{
	push_stack(&input->a, &input->b);
	write(1, "pb\n", 3);
	input->ops_sum[PB]++;
}
