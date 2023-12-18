/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:47:00 by acroue            #+#    #+#             */
/*   Updated: 2023/12/18 17:08:15 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_a	*swap_elements(t_a *list, size_t length, char c)
{
	t_a	*tmp;

	if (length == 1)
		return (list);
	printf("s%c\n", c);
	tmp = list->next;
	list->previous->next = tmp;
	tmp->next->previous = list;
	list->next = tmp->next;
	tmp->next = list;
	tmp->previous = list->previous;
	list->previous = tmp;
	return (tmp);
}

void	push(t_a **src, t_a **dest, char c)
{
	t_a	*tmp;

	printf("p%c\n", c);
	(*src)->previous->next = (*src)->next;
	(*src)->next->previous = (*src)->previous;
	tmp = (*src);
	(*src) = (*src)->next;
	if (!(*dest))
	{
		(*dest) = tmp;
		(*dest)->next = (*dest);
		(*dest)->previous = (*dest);
		return ;
	}
	(*dest)->previous->next = tmp;
	tmp->previous = (*dest)->previous;
	(*dest)->previous = tmp;
	tmp->next = (*dest);
	(*dest) = tmp;
}

void	rotate(t_a **a, t_a **b, char *str)
{
	t_a	**tmp;

	if (str[0] == 'a' || (str[0] == 'r' && str[1] == 'a'))
		tmp = a;
	else if (str[0] == 'b' || (str[0] == 'r' && str[1] == 'b'))
		tmp = b;
	if (str[0] == 'a' || str[0] == 'b')
		(*tmp) = (*tmp)->next;
	if (str[0] == 'r' && (str[1] == 'a' || str[1] == 'b'))
		(*tmp) = (*tmp)->previous;
	if (str[0] == 'r' && str[1] == '\0')
	{
		(*a) = (*a)->next;
		(*b) = (*b)->next;
	}
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
	{
		(*a) = (*a)->previous;
		(*b) = (*b)->previous;
	}
	ft_printf("r%s\n", str);
}

size_t	move_b(t_a **list, t_a **b, size_t length)
{
	size_t	i;

	i = 0;
	while (((length - i + 1) / 2) > 3 && i < (length / 2))
	{
		if ((size_t)(*list)->rank < (length / 2))
		{
			printf("\n%d vers b en bas\n", (*list)->value);
			push(list, b, 'b');
			i++;
		}
		else
		{
			(*list) = (*list)->next;
			printf("ra\n");
		}
	}
	while (i < length - 3)
	{
		printf("\n%d vers b en haut\n", (*list)->value);
		push(list, b, 'b');
		i++;
	}
	return (i);
}

/* 
	Here we have the functions that are going to allow us to push and
	you guessed it... swap elements in our linked list.
 */

/* t_a	*swap_elements(t_a *list, size_t length, char c)
{
	int	tmp;

	ft_printf("s%c\n", c);
	if (length == 1)
		return (list);
	// t_a	*temp;
	// temp = list->next;
	// printf("\n:%d %d:\n", list->value, temp->value);
	// list->previous->next = temp;
	// temp->previous = list->previous;
	// list->previous = temp;
	// temp = temp->next;
	// temp->next = list;
	// printf("\n:%d %d:\n", list->value, temp->value);
	// return (temp);
	printf("\n%d %d\n", list->value, list->next->value);
	printf("\n%d %d\n", list->rank, list->next->rank);
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	tmp = list->rank;
	list->rank = list->next->rank;
	list->next->rank = tmp;
	return (list);
} */

/* t_a	*push(t_a *src, t_a *dest, char c)
{
	ft_printf("s%c\n", c);
	src->previous->next = src->next;
	src->next->previous = src->previous;
	if (!dest)
	{
		src->next = src;
		src->previous = src;
		return (src);
	}
	src->next = dest;
	src->previous = dest->previous;
	dest->previous->next = src;
	dest->previous = src;
	return (src);
}

t_a	*move_b(t_a *list, t_a *b, size_t length)
{
	size_t	i;

	i = 0;
	while (((length / 2) - i) > 3 && i < (length / 2))
	{
		printf("length/2 - i: %zu\nrank: %d median: %zu\n", (length/2)-i, list->rank, (length / 2));
		if ((size_t)list->rank < (length / 2))
		{
			list = list->next;
			b = push(list->previous, b, 'b');
			i++;
		}
		else
		{
			list = list->next; // faire RA
		}
	}
	while (i < length)
	{
		list = list->next;
		b = push(list->previous, b, 'b');
		i++;
	}
	return (b);
} */
