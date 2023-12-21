/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:28 by acroue            #+#    #+#             */
/*   Updated: 2023/12/21 13:34:03 by acroue           ###   ########.fr       */
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
	node->cost.rr = 0;
	node->cost.rrr = 0;
	node->cost.total = 0;
}

void	def_cost(t_a **list, t_a **b, size_t length, size_t index)
{
	size_t	i;

	list = NULL;
	printf("\n1");
	i = 0;
	(*b)->cost.rrb = length - index; // si on est plus proche de la fin alors move down
	(*b)->cost.rb = index; // si + proche du debut alors move up
}

void	sunk_cost(t_a **list, t_a **b, size_t len)
{
	t_a		*tmp;
	size_t	i;

	i = 0;
	tmp = (*list);
	printf("2");
	printf("\n%d %d\n", (*b)->rank, tmp->rank);
	while ((*b)->rank > tmp->rank)
	{
		printf("\n%d %d\n", (*b)->rank, tmp->rank);
		i++;
		tmp = tmp->next;
	}
	printf("\nsunk cost : len = %zu i = %zu\n", len, i);
	(*b)->cost.rra = len - i;
	(*b)->cost.ra = i;
	// ICI comparer rrb et rra puis rb et ra pour faire des rrr ou rr et -- sur les ra, rb, rra, rrb
} // ici on compte le cout de deplacer la node a sa place

void	justice(t_a **list, t_a **b, size_t up, size_t down)
{
	list = NULL;
	up = 0;
	down = 0;
	if ((*b)->cost.rra > (*b)->cost.ra + (*b)->cost.rrb)
		(*b)->cost.rra = 0; // JE NE SUIS PAS SUR DE CA
	up += (*b)->cost.ra;
	up += (*b)->cost.rb;
	down += (*b)->cost.rra;
	down += (*b)->cost.rrb;
	printf("\nup %zu is down %zu\n", up, down);
	if (up <= down)
	{
		(*b)->cost.rra = 0;
		(*b)->cost.rrb = 0;
		(*b)->cost.rrr = 0;
	}
	else
	{
		(*b)->cost.ra = 0;
		(*b)->cost.rb = 0;
		(*b)->cost.rr = 0;
	}
	// ICI verifier si le cout de up est sup a down et clear le mauvais
}

void	compare_cost(t_a **list, t_a **b, size_t len)
{
	size_t	up;
	size_t	down;

	up = 0;
	down = 0;
	len = 0;
	printf("3 PREMIER = %d\n", (*b)->value);
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
	justice(list, b, up, down);
}

static size_t	sum_total(t_a *node)
{
	t_cost	temp;
	
	temp = node->cost;
	return (temp.ra + temp.rb + temp.rra + temp.rrb + temp.rr + temp.rrr);
}

void	pruc(t_a *list)
{
	t_a		*temp;

	if (!list)
	{
		printf("\nempty list\n");
		return ;
	}
	// printf("\nPREMIER = %d\n", list->value);
	temp = list;
	temp->cost.total = sum_total(temp);
	printf("|val|ra |rb |rra|rrb|rr |rrr|tot|");
	printf("\n\n|%3d| %zu | %zu | %zu | %zu | %zu | %zu | %zu |", temp->value, temp->cost.ra, temp->cost.rb, temp->cost.rra, temp->cost.rrb, temp->cost.rr, temp->cost.rrr, list->cost.total);
	list = list->next;
	while (list != temp)
	{
		list->cost.total = sum_total(list);
		printf("\n\n|%3d| %zu | %zu | %zu | %zu | %zu | %zu | %zu |", list->value, list->cost.ra, list->cost.rb, list->cost.rra, list->cost.rrb, list->cost.rr, list->cost.rrr, list->cost.total);
		list = list->next;
	}
	printf("\n");
}

void	count_cost(t_a **list, t_a **b, size_t len, size_t b_len)
{
	t_a		*temp;
	size_t	i;

	printf("\nPREMIER = %d\n", (*b)->value);
	i = 0;
	temp = (*b)->previous;
	while (1)
	{
		if ((*b) == temp)
		{
			def_cost(list, b, b_len, i);
			sunk_cost(list, b, len - b_len);
			compare_cost(list, b, len);
			(*b) = (*b)->next;
			break;
		}
		def_cost(list, b, b_len, i);
		sunk_cost(list, b, len - b_len);
	// pruc(temp->next);
		compare_cost(list, b, len);
		(*b) = (*b)->next;
		i++;
	}
	pruc(temp->next);
	// faire le check de tout les mouvements et les comparer
} // faire le count des couts + le temp

/* 
	Here we are calculating the cost of moving each node to their right spot.
 */
