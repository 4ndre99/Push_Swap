/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:23:44 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 15:31:58 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder(t_input *input)
{
	t_stack	*stack;
	t_stack	*iterate;
	double	mistakes;
	double	total_pairs;

	stack = input->a;
	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		iterate = stack->next;
		while (iterate)
		{
			total_pairs += 1;
			if (stack->value > iterate->value)
				mistakes += 1;
			iterate = iterate->next;
		}
		stack = stack->next;
	}
	input->disorder = mistakes / total_pairs;
}

t_stack	*check_greatest(t_stack *stack)
{
	t_stack	*pos;
	int		max;

	pos = stack;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			pos = stack;
			break ;
		}
		stack = stack->next;
	}
	return (pos);
}

t_stack	*check_smallest(t_stack *stack)
{
	t_stack	*pos;
	int		min;

	pos = stack;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			pos = stack;
		}
		stack = stack->next;
	}
	return (pos);
}

int	sum_ops(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= RRR)
		j += a->ops[i++];
	return (j);
}

void	lowest_to_top(t_input *input)
{
	t_stack	*lowest;

	lowest = check_smallest(input->a);
	if (lowest->index <= lst_size(input->a) / 2)
	{
		while (!is_sorted(input))
			ra(input);
	}
	else
	{
		while (!is_sorted(input))
			rra(input);
	}
}
