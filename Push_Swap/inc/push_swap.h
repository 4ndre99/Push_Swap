/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:04:47 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/10 15:46:26 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "parsing.h"

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

typedef struct s_plan
{
	int	ops[RRR + 1];
}	t_plan;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*target;
	t_plan			plan;
}					t_stack;

typedef enum e_strat
{
	INVALID,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strat;

typedef struct s_input
{
	t_stack			*a;
	t_stack			*b;
	t_strat			strat;
	int				bench;
	double			disorder;
	unsigned long	ops_sum[RRR + 1];
}					t_input;

//benchmark
void	write_strat(t_strat strat);
void	write_form(t_input *input);
int		total_ops(t_input *input);
void	write_bench(t_input *input);
void	valid_run(t_input *input);

//operations
void	swap_stack(t_stack **stack);
void	sa(t_input *input);
void	sb(t_input *input);
void	ss(t_input *input);
void	push_stack(t_stack **src, t_stack **dst);
void	pa(t_input *input);
void	pb(t_input *input);
void	rotate_stack(t_stack **stack);
void	ra(t_input *input);
void	rb(t_input *input);
void	rr(t_input *input);
void	reverse_rotate_stack(t_stack **stack);
void	rra(t_input *input);
void	rrb(t_input *input);
void	rrr(t_input *input);

//utils
void	update_plan_a(t_input *input);
void	update_plan_b(t_input *input);
void	update_index(t_stack *stack);
void	update_target_a(t_input *input);
void	update_target_b(t_input *input);
void	disorder(t_input *input);
t_stack	*check_greatest(t_stack *stack);
t_stack	*check_smallest(t_stack *stack);
int		sum_ops(t_plan plan);
void	lowest_to_top(t_input *input);
void	lowest_to_top(t_input *input);

//manipulate
void	lst_addback(t_input *input, int value);
void	free_stack(t_stack *stack);
int		lst_size(t_stack *stack);

//sort
void	pb_cheapest(t_input *input);
t_stack	*cheapest_node(t_stack *a);
void	pa_cheapest(t_input *input);
void	sort_three(t_input *input);
void	sort_radix(t_input *input);
void	sort(t_input *input);
void	sort_simple(t_input *input);
void	sort_medium(t_input *input);
void	sort_complex(t_input *input);
void	sort_adaptive(t_input *input);

//main
int		check_args(t_input *input, char **argv);
int		init_stack(t_input *input, char **argv);
void	init_input(t_input *input);

#endif