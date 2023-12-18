/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:56:44 by acroue            #+#    #+#             */
/*   Updated: 2023/12/18 11:01:10 by acroue           ###   ########.fr       */
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
	int			value;
	int			rank;
	struct s_a	*next;
	struct s_a	*previous;
}	t_a;

t_a		*check_rank(t_a *list, size_t length);
char	*ft_jointab(char **tab, size_t i, int length);
t_a		*swap_elements(t_a *list, size_t length, char c);
t_a		*push(t_a *src, t_a *dest, char c);
t_a		*move_b(t_a *list, t_a *b, size_t length);
t_a		*define_a(char *str, size_t length);
void	free_list(t_a *list, size_t length);
void	lprint(t_a *list);
void	rprint(char *str);

#endif
