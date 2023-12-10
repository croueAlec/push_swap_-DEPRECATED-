/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:26 by acroue            #+#    #+#             */
/*   Updated: 2023/12/10 20:19:15 by acroue           ###   ########.fr       */
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

static size_t	move_index(char *str, long ln)
{
	size_t	i;

	i = num_len(ln);
	while (str[i] != '\0' && str[i] == ' ')
	{
		i++;
	}
	return (i);
}

t_a	*define_a(char *str)
{
	long	ln;
	t_a		*node;
	t_a		*first_node;
	t_a		*next_node;

	node = malloc(sizeof(t_a));
	first_node = node;
	node->previous = NULL;
	while (*str)
	{
		next_node = malloc(sizeof(t_a));
		node->next = next_node;
		next_node->previous = node;
		next_node->next = NULL;
		ln = ft_atol(str);
		if (!(ln <= 2147483647 && ln >= -2147483648))
			return (err_print("invalid number"), NULL);
		str += move_index(str, ln);
		printf("\n>%s<\n", str);
		node->value = ln;
		if (*str != '\0')
			node = next_node;
	}
	first_node->previous = node;
	return (free(next_node), node->next = first_node);
}

void	lprint(t_a *list)
{
	int		temp;

	temp = list->value;
	printf("\n%d", temp);
	list = list->next;
	while (list->value != temp)
	{
		printf("\n%d", list->value);
		list = list->next;
		free(list->previous);
	}
	free(list);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	t_a		*list;

	if (argc == 1)
		return (err_print("too few arguments"), 0);
	tmp = ft_jointab(&argv[1], 0, 0);
	if (!tmp)
		return (0);
	str = ft_strtrim(tmp, " ");
	printf("\n|%s|\n|%s|\n", str, tmp);
	list = define_a(str);
	lprint(list);
	return (free(tmp), free(str), 0);
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
//
//
//
// note du dimanche 10/12/23, verifier les duplicatas de nombres bisou
