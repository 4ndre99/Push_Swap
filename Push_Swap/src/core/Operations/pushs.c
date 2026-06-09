/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:14:38 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/01 16:21:57 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dst;
	if (*dst)
		(*dst)->prev = temp;
	*dst = temp;
	update_index(*src);
	update_index(*dst);
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
