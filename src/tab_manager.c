/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:33:37 by acroue            #+#    #+#             */
/*   Updated: 2023/12/20 16:00:34 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static size_t	num_len(long n)
{
	size_t	length;

	length = 1;
	if (n < 0 && length++)
		n *= -1;
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static size_t	move_index(char *str, long ln)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		j++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (num_len(ln) != j)
		return (0);
	return (i + j);
}

static t_a	*add_back(t_a **list, t_a **end)
{
	t_a	*node;
	t_a	*last;

	node = malloc(sizeof(t_a));
	if (!node)
		return (NULL);
	last = (*list)->previous;
	node->next = (*list);
	node->previous = last;
	last->next = node;
	(*list)->previous = node;
	node->rank = -1;
	zero_cost(node);
	*end = node;
	return (node);
}

static t_a	*def_first(void)
{
	t_a	*node;

	node = malloc(sizeof(t_a));
	if (!node)
		return (NULL);
	node->previous = node;
	node->next = node;
	node->rank = -1;
	zero_cost(node);
	return (node);
}

t_a	*define_a(char *str, size_t length)
{
	long	ln;
	t_a		*node;
	t_a		*head;
	size_t	i;
	size_t	index;

	i = 0;
	node = def_first();
	if (!node)
		return (rprint("malloc failed"), NULL);
	head = node;
	while (i++ < length)
	{
		ln = ft_atol(str);
		index = move_index(str, ln);
		if (!(ln <= INT_MAX && ln >= INT_MIN) || index == 0)
			return (rprint("invalid number"), free_list(head), NULL);
		if (i > 1 && !add_back(&head, &node))
			return (free_list(head), NULL);
		node->value = ln;
		str += index;
	}
	return (head);
}

/* 
	Here we create our tab A and put the values inside.
	We also check if values are between INT_MAX and INT_MIN
 */
