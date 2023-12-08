/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:26 by acroue            #+#    #+#             */
/*   Updated: 2023/12/08 17:41:48 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	num_len(long n)
{
	size_t	length;

	length = 1;
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length);
}

t_a	*define_a(char *str)
{
	long	ln;
	size_t	i;
	t_a		*node;
	t_a		*next_node;

	i = 0;
	node = malloc(sizeof(t_a));
	node->previous = NULL;
	while (*str)
	{
		next_node = malloc(sizeof(t_a));
		next_node->previous = node;
		next_node->next = NULL;
		ln = ft_atol(str);
		if (!(ln <= 2147483647 && ln >= -2147483648))
			return (err_print("invalid number"), NULL);
		str += num_len(ln);
		node->value = ln;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 1)
		return (err_print("too few arguments"), 0);
	str = ft_jointab(&argv[1], 0, 0);
	if (!str)
		return (0);
	define_a(str);
	return (0);
}

void	err_print(char *str)
{
	write(2, "Error : ", 9);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
// ne pas oublier de retirer cette ligne dans le err_print
//
//
//
// j'ai fait une partie du parsing, les entrees sont stockees dans
// un tableau de chars, maintenant il faut le verifier et le split
//
// verifier si les chars ne sont pas de 0-9 ou "-+ " verifier qu'un
// moins ou un plus est bien suivi d'un nombre
//
//
// au dessus c'est fait maintenant il faut separer dans une list chainee
//
//
//
//
//
// note du vendredi 8/12/23, le parsing est fait mes inputs sont safes
