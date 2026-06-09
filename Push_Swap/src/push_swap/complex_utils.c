/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcooli <marcooli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:47:34 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/09 15:21:41 by marcooli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_int(&array[i], &array[j]);
		}
		j++;
	}
	swap_int(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quicksort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		quicksort(array, start, pivot_index - 1);
		quicksort(array, pivot_index + 1, end);
	}
}

void	sort_radix(t_input *input)
{
	int	biggest_value;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = lst_size(input->a);
	biggest_value = size - 1;
	max_bits = 0;
	while ((biggest_value >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((input->a->value >> i) & 1) == 1)
				ra(input);
			else
				pb(input);
		}
		while (lst_size(input->b) > 0)
			pa(input);
	}
}

void	rank_values(t_input *input)
{
	int		*array;
	t_stack	*j;
	int		k;

	array = stack_to_array(input->a);
	quicksort(array, 0, lst_size(input->a) - 1);
	k = 0;
	while (k < lst_size(input->a))
	{
		j = input->a;
		while (j)
		{
			if (array[k] == j->value)
				j->value = k;
			j = j->next;
		}
		k++;
	}
}
