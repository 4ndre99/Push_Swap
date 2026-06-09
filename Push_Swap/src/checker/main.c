/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:55:50 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 15:57:50 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_reverse_r(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_stack(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_stack(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_b);
	}
}

static void	apply_operation(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_stack(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_stack(stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_stack(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_stack(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
	else
		apply_reverse_r(line, stack_a, stack_b);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!valid_op(line))
		{
			print("Error\n");
			return ;
		}
		apply_operation(line, stack_a, stack_b);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		print("OK\n");
	else
		print("KO\n");
}

static int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**copy;

	copy = numbers(argv + 1);
	if (argc == 2)
		copy = split(argv[1], ' ');
	if (!valid_nums(copy))
		return (write(2, "Error\n", 6), 1);
	stack_a = init_list(copy);
	stack_b = NULL;
	checker(&stack_a, &stack_b);
	return (0);
}