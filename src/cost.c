/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:28 by acroue            #+#    #+#             */
/*   Updated: 2023/12/20 12:59:16 by acroue           ###   ########.fr       */
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
}

void	def_cost(t_a **list, t_a **b, size_t length, size_t index)
{
	size_t	i;

	i = 0;
	(*b)->cost.rrb = length - index; // si on est plus proche de la fin alors move down
	(*b)->cost.rb = index; // si + proche du debut alors move up
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
	(*b)->cost.rra = len - i;
	(*b)->cost.ra = i;
	// ICI comparer rrb et rra puis rb et ra pour faire des rrr ou rr et -- sur les ra, rb, rra, rrb
} // ici on compte le cout de deplacer la node a sa place

void	justice(t_a **list, t_a **b, size_t up, size_t down)
{
	if (up <= down)
	{
		(*b)->cost.rra = 0;
		(*b)->cost.rrb = 0;
		(*b)->cost.rrr = 0;
	}
	else
	{
		(*b)->cost.rra = 0;
		(*b)->cost.rrb = 0;
		(*b)->cost.rrr = 0;
	}
	
	// ICI verifier si le cout de up est sup a down et clear le mauvais
}

void	compare_cost(t_a **list, t_a **b, size_t len)
{
	size_t	up;
	size_t	down;

	while ((*b)->cost.ra > 0 && (*b)->cost.rb > 0)
	{
		(*b)->cost.ra--;
		(*b)->cost.rb--;
		up = ++(*b)->cost.rr;
	}
	while ((*b)->cost.rra > 0 && (*b)->cost.rrb > 0)
	{
		(*b)->cost.rra--;
		(*b)->cost.rrb--;
		down = ++(*b)->cost.rrr;
	}
	up += (*b)->cost.ra;
	up += (*b)->cost.rb;
	down += (*b)->cost.rra;
	down += (*b)->cost.rrb;
	justice(list, b, up, down);
}

// void	truc_cost(t_a **list, t_a **b)
// {
// 	if ()
// }

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
