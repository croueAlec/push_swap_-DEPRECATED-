/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:16:19 by acroue            #+#    #+#             */
/*   Updated: 2023/12/18 17:06:11 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	is_node_sorted(t_a *node, t_a *next)
{
	if (node->value < next->value)
		return (1);
	else
		return (0);
}

int	is_list_sorted(t_a *list)
{
	t_a		*tmp;
	size_t	i;

	i = 0;
	tmp = list->previous;
	while (list != tmp)
	{
		if (!is_node_sorted(list, list->next))
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

void	sort_three(t_a **list, size_t length)
{
	while (!is_list_sorted((*list)))
	{
		if (!is_node_sorted((*list), (*list)->next))
			swap_elements((*list), length, 'a');
		else
			rotate(list, NULL, "ra");
	}
}
