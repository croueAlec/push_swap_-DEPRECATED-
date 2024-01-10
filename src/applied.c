/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applied.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:04 by acroue            #+#    #+#             */
/*   Updated: 2024/01/10 15:13:12 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

size_t	applied_energistics_2(t_a *list, size_t len)
{
	size_t	i;

	i = 0;
	list = list->previous;
	while (list->rank != 1)
	{
		printf("\n%d\n", list->rank);
		i++;
		list = list->next;
	}
	if (i < (len / 2))
		while (i--)
			rotate(&list, NULL, "ra");
	else
		while (i--)
			rotate(&list, NULL, "a");
	// rotate(&list, NULL, "ra");
	// rotate(&list, NULL, "ra");
	return (i);
}

void	applied_energistics(t_a *list, t_a *b, size_t len, size_t b_len)
{
	// size_t	offset;
	while (b_len)
	{
		if (b->value == 2)
			fprintf(stderr, "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n");
		count_cost(&list, &b, len, b_len);
		// lprint(list);
		// printf("\n\t\t\t\t%zu\n", b_len);
		// printf("\n current rb:%zu\n", b->cost.rb);
		while (b->cost.rb--)
			rotate(&list, &b, "b");
		// printf("\n current rrb:%zu\n", b->cost.rrb);
		while (b->cost.rrb--)
			rotate(&list, &b, "rb");
		// printf("\n current rr:%zu\n", b->cost.rr);
		while (b->cost.rr--)
			rotate(&list, &b, "r");
		// printf("\n current rrr:%zu\n", b->cost.rrr);
		while (b->cost.rrr--)
			rotate(&list, &b, "rr");
		// printf("\n current ra:%zu\n", b->cost.ra);
		while (b->cost.ra--)
		{
			// printf("%d\n", b->value);
			rotate(&list, &b, "a");
		}
		// printf("\n current rra:%zu\n", b->cost.rrr);
		while (b->cost.rra--)
			rotate(&list, &b, "ra");
		push(&b, &list, 'a');
		b_len--;
		len++;
	}
	rotate(&list, &b, "ra");
	// offset = applied_energistics_2(list, len);
}


/* 11 6 2 5 13 8 17 20 7 3 10 16 9 4 12 14 19 18 1 15 tester ca et fix le 2 qui ne va pas au bon endroit */
