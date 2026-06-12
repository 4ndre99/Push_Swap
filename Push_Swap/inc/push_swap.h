/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:04:47 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 17:08:52 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "core.h"

typedef struct s_input
{
	t_stack			*a;
	t_stack			*b;
	t_strat			strat;
	int				bench;
	float			disorder;
	unsigned long	ops_sum[RRR + 1];
}					t_input;

void	disorder(t_input *input);
void	write_strat(t_strat strat);
void	write_form(t_input *input);
int		total_ops(t_input *input);
void	write_bench(t_input *input);
void	valid_run(t_input *input);
void	sa(t_input *input);
void	sb(t_input *input);
void	ss(t_input *input);
void	pa(t_input *input);
void	pb(t_input *input);
void	ra(t_input *input);
void	rb(t_input *input);
void	rr(t_input *input);
void	rra(t_input *input);
void	rrb(t_input *input);
void	rrr(t_input *input);
void	update_plan_a(t_input *input);
void	update_plan_b(t_input *input);
void	update_target_a(t_input *input);
void	update_target_b(t_input *input);
t_stack	*check_greatest(t_stack *stack);
t_stack	*check_smallest(t_stack *stack);
int		sum_ops(t_plan plan);
void	lowest_to_top(t_input *input);
void	pb_cheapest(t_input *input);
t_stack	*cheapest_node(t_stack *a);
void	pa_cheapest(t_input *input);
void	sort(t_input *input);
void	sort_three(t_input *input);
void	sort_simple(t_input *input);
void	sort_medium(t_input *input);
void	sort_chunk(t_input *in, int len, int cs);
void	sort_complex(t_input *input);
void	sort_radix(t_input *input);
void	sort_adaptive(t_input *input);
void	twist_it(t_input *input);
void	biggest_to_A(t_input *in, int cs);
int		ft_sqrt(int nb);
void	rank_values(t_input *input);
int		*stack_to_array(t_stack *a);
void	init_input(t_input *input);
void	check_flags(t_input *input, char **argv);

#endif