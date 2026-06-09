/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:32:48 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/08 18:23:27 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(t_input *input, char **argv)
{
	int	i;

	i = 0;
	if (ft_strcmp(argv[i], "--bench") == 0)
	{
		input->bench = 1;
		i++;
	}
	if (is_strat(argv[i]))
		input->strat = is_strat(argv[i++]);
	return (validate_numbers(argv + i));
}

int	init_stack(t_input *input, char **argv)
{
	int	i;

	i = 1;
	while (ft_strncmp(argv[i], "--", 2) == 0)
		i++;
	return (create_stack(input, argv + i));
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
	char	**polished;

	if (argc == 1)
		return (0);
	polished = numbers(argv + 1);
	init_input(&input);
	if (!check_args(&input, polished))
		return (write(2, "Error\n", 6), 1);
	if (!init_stack(&input, polished))
		return (write(2, "Error\n", 6), 1);
	disorder(&input);
	if (!input.disorder)
		return (valid_run(&input), 0);
	sort(&input);
	return (valid_run((&input)), 0);
}
