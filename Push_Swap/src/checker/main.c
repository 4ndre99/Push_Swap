/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:55:50 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/11 15:44:28 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_reverse_r(char *line, t_stack **stack_a, t_stack **stack_b)
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

static void	apply_operation(char *line, t_stack **stack_a, t_stack **stack_b)
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

void	checker(t_stack **stack_a, t_stack **stack_b)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!parsing(&stack_a, argv))
		return(write(2, "Error\n", 6), 0);
	checker(&stack_a, &stack_b);
	return (0);
}