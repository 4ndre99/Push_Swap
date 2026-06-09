/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:41:21 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 15:17:58 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addback(t_input *input, int value)
{
	t_stack	*tmp;
	t_stack	*node;
	int		i;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (free_stack(input->a), NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->target = NULL;
	i = 0;
	while (i <= RRR)
		node->ops[i++] = 0;
	if (!input->a)
	{
		input->a = node;
		return ;
	}
	tmp = input->a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	lst_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
