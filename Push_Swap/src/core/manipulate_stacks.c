/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:41:21 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/11 16:14:51 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	lst_addback(t_stack **a, int value)
{
	t_stack	*node;
	t_stack *tmp;
	t_plan	plan;

	plan = (t_plan){0};
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		free_stack(a);
		return ;
	}
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->target = NULL;
	node->plan = plan;
	if (!*a)
	{
		*a = node;
		return ;
	}

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
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

void	update_index(t_stack *stack)
{
	int		index;

	index = 0;
	while (stack)
	{
		stack->index = index++;
		stack = stack->next;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
