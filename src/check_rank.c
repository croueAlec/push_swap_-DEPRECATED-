/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:35:51 by acroue            #+#    #+#             */
/*   Updated: 2023/12/15 14:21:04 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	find_smallest_int(t_a *list, size_t length)
{
	size_t	i;
	int		tmp;

	i = -1;
	while (++i < length && list->rank != -1)
		list = list->next;
	tmp = list->value;
	i = -1;
	while (++i < length)
	{
		// printf("\n%d:%d\t%d\n", tmp, list->value, list->rank);
		// if (tmp > list->value && list->rank == -1)
			// printf("\n\t\t%d\n", tmp);
		if (tmp > list->value && list->rank == -1)
			tmp = list->value;
		list = list->next;
	}
	// printf("\n%d < ici temp\n", tmp);
	return (tmp);
}

t_a	*check_rank(t_a *list, size_t length)
{
	size_t	i;
	size_t	j;
	int		tmp;
	t_a		*start;

	start = list;
	i = 0;
	while (i < length)
	{
		tmp = find_smallest_int(list, length);
		j = 0;
		while (j < length)
		{
			if (tmp == list->value)
			{
				// printf("rank %d\n", tmp);
				list->rank = ++i;
			}
			list = list->next;
			j++;
		}
	}
	return (start);
}

/* 
	Find and assign a rank to the values in the nodes.
	We use this rank to sort using the median when pushing into B 
*/
