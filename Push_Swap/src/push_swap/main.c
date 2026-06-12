/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:32:48 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/12 13:29:24 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags(t_input *input, char **argv)
{
	int	i;

	i = 1;
	if (ft_strcmp(argv[i], "--bench") == 0)
	{
		input->bench = 1;
		i++;
	}
	if (ft_strcmp(argv[i], "--simple") == 0)
		input->strat = SIMPLE;
	else if (ft_strcmp(argv[i], "--medium") == 0)
		input->strat = MEDIUM;
	else if (ft_strcmp(argv[i], "--complex") == 0)
		input->strat = COMPLEX;
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
		input->strat = ADAPTIVE;
}

void	init_input(t_input *input)
{
	int	i;

	i = 0;
	input->a = NULL;
	input->b = NULL;
	input->strat = ADAPTIVE;
	input->bench = 0;
	input->disorder = 0.0;
	while (i <= RRR)
		input->ops_sum[i++] = 0;
}

int	main(int argc, char **argv)
{
	t_input	input;

	if (argc == 1)
		return (0);
	init_input(&input);
	if (!parsing(&input.a, argv))
	{
		free_stack(&input.a);
		free_stack(&input.b);
		return (write(2, "Error\n", 6), 0);
	}
	check_flags(&input, argv);
	disorder(&input);
	if (is_sorted(input.a))
		return (valid_run(&input), 0);
	sort(&input);
	return (valid_run((&input)), 0);
}
