/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:47:00 by acroue            #+#    #+#             */
/*   Updated: 2023/12/12 07:12:38 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_a	*swap_elements(t_a *list, size_t length)
{
	int	tmp;
	write(1, "sa\n", 3);
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
	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
	return (list);
}
