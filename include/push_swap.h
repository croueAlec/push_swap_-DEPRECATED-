/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2023/12/19 18:25:16 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_a
{
	int				value;
	int				rank;
	struct s_a		*next;
	struct s_a		*previous;
	struct s_cost	cost;
}	t_a;

typedef struct s_cost
{
	size_t		ra;
	size_t		rb;
	size_t		rra;
	size_t		rrb;
	size_t		rr;
	size_t		rrr;
	size_t		total;
}	t_cost;


t_a		*check_rank(t_a *list, size_t length);
void	zero_cost(t_a *node);
void	def_cost(t_a **list, t_a **b, size_t length, size_t index);
void	count_cost(t_a **list, t_a **b, size_t len, size_t length);
char	*ft_jointab(char **tab, size_t i, int length);
t_a		*swap_elements(t_a *list, size_t length, char c);
void	push(t_a **src, t_a **dest, char c);
void	rotate(t_a **a, t_a **b, char *str);
size_t	move_b(t_a **list, t_a **b, size_t length);
t_a		*define_a(char *str, size_t length);
void	free_list(t_a *list);
void	lprint(t_a *list);
void	rprint(char *str);
int		is_node_sorted(t_a *list, t_a *next);
int		is_list_sorted(t_a *list);
void	sort_three(t_a **list, size_t length);
void	sorting(t_a **list, t_a **b, size_t length);

#endif
