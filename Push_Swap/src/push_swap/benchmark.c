/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:10:21 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 19:23:01 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_strat(t_strat strat)
{
	if (strat == 1)
		print("Simple");
	if (strat == 2)
		print("Medium");
	if (strat == 3)
		print("Complex");
	if (strat == 4)
		print("Adaptive");
}

void	write_form(t_input *input)
{
	if (input->strat == 1)
		print("O(n^2)\n");
	if (input->strat == 2)
		print("O(n\xe2\x88\x9an)\n");
	if (input->strat == 3)
		print("O(n log n)\n");
	if (input->strat == 4)
	{
		if (input->disorder < 0.2)
			print("O(n^2)\n");
		if (input->disorder >= 0.2 && input->disorder < 0.5)
			print("O(n\xe2\x88\x9an)\n");
		if (input->disorder >= 0.5)
			print("O(n log n)\n");
	}
}

int	total_ops(t_input *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i <= RRR)
		count += input->ops_sum[i++];
	return (count);
}

void	write_bench(t_input *input)
{
	if (input->disorder == 1)
		print("[bench] disorder:	100.00%%\n");
	else
		print("[bench] disorder:	%f\n", (input->disorder) * 100);
	print("[bench] strategy:	");
	write_strat(input->strat);
	write(2, "  /  ", 5);
	write_form(input);
	print("[bench] total_ops:	%d\n", total_ops(input));
	print("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		input->ops_sum[SA], input->ops_sum[SB], input->ops_sum[SS],
		input->ops_sum[PA], input->ops_sum[PB]);
	print("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d",
		input->ops_sum[RA], input->ops_sum[RB], input->ops_sum[RR],
		input->ops_sum[RRA]);
	print(" rrb:  %d  rrr:  %d\n", input->ops_sum[RRB], input->ops_sum[RRR]);
}

void	valid_run(t_input *input)
{
	if (input->bench == 1)
		write_bench(input);	
	free_stack(&input->a);
	free_stack(&input->b);
}
