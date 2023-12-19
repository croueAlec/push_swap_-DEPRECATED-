/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:28 by acroue            #+#    #+#             */
/*   Updated: 2023/12/19 18:26:28 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	zero_cost(t_a *node)
{
	node->cost.ra = 0;
	node->cost.rb = 0;
	node->cost.rra = 0;
	node->cost.rrb = 0;
	node->cost.total = 0;
}

void	def_cost(t_a **list, t_a **b, size_t length, size_t index)
{
	size_t	i;

	i = 0;
	if (index > (length / 2))
		(*b)->cost.rrb = length - index; // si on est plus proche de la fin alors move down
	else
		(*b)->cost.rb = index; // si + proche du debut alors move up
	(*b)->cost.total += (*b)->cost.rrb;
	(*b)->cost.total += (*b)->cost.rb;
}

void	sunk_cost(t_a **list, t_a **b, size_t len)
{
	t_a		*temp;
	size_t	i;

	i = 0;
	temp = (*list);
	while ((*b)->rank < temp->rank)
	{
		i++;
		temp = temp->next;
	}
	if (i > (len / 2))
		(*b)->cost.rra = len - i;
	else
		(*b)->cost.ra = i;
	(*b)->cost.total += (*b)->cost.rra;
	(*b)->cost.total += (*b)->cost.ra;
	
	// ICI comparer rrb et rra puis rb et ra pour faire des rrr ou rr et -- sur les ra, rb, rra, rrb
	
} // ici on compte le cout de deplacer la node a sa place

void	count_cost(t_a **list, t_a **b, size_t len, size_t b_len)
{
	t_a		*temp;
	size_t	i;

	i = 0;
	temp = (*b)->previous;
	while (1)
	{
		if ((*b) == temp)
		{
			def_cost(list, b, b_len, i);
			break;
		}
		def_cost(list, b, b_len, i);
		(*b) = (*b)->next;
		i++;
	}
} // faire le count des couts + le temp

/* 
	Here we are calculating the cost of moving each node to their right spot.
 */
