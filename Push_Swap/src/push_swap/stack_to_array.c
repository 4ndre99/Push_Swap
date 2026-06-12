/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:42:28 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 12:33:16 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a)
{
	int		i;
	int		*array;
	t_stack	*b;

	i = 0;
	b = a;
	while (a)
	{
		a = a->next;
		i++;
	}
	array = malloc(i * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (b)
	{
		array[i++] = b->value;
		b = b->next;
	}
	return (array);
}
