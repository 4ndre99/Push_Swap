/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:22:32 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/11 14:22:52 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
