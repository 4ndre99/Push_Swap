/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:23:02 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/11 14:23:34 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
