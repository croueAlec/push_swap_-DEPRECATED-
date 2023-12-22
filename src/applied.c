/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applied.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:16:04 by acroue            #+#    #+#             */
/*   Updated: 2023/12/22 15:09:11 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	applied_energistics(t_a *list, t_a *b, size_t len, size_t b_len)
{
	while (b_len)
	{
		count_cost(&list, &b, len, b_len);
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
		push(&b, &list, 'a');
		// printf("\n current ra:%zu\n", b->cost.ra);
		while (b->cost.ra--)
			rotate(&list, &b, "a");
		// printf("\n current rra:%zu\n", b->cost.rrr);
		while (b->cost.rra--)
			rotate(&list, &b, "ra");
		b_len--;
		len++;
	}
}
