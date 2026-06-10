/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:06:58 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/10 15:21:29 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	check_flags(t_input *input, char **argv)
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

int	parsing(t_input *input, char **argv)
{
	int	i;

	check_flags(input, argv);
	i = 1;
	while (ft_strncmp(argv[i], "--", 2) == 0)
		i++;
	while (argv[i])
	{
		if(!parse_argument(input, argv[i]))
			return (0);
		i++;
	}
	return (check_dups(input));
}
