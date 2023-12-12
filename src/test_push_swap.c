/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:26 by acroue            #+#    #+#             */
/*   Updated: 2023/12/12 11:13:27 by acroue           ###   ########.fr       */
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

static t_a	*def_next(t_a *node)
{
	t_a	*next_node;

	next_node = malloc(sizeof(t_a));
	next_node->previous = node;
	next_node->next = NULL;
	return (next_node);
}

t_a	*define_a(char *str, size_t length)
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
		next_node = def_next(node);
		node->next = next_node;
		ln = ft_atol(str);
		if (!(ln <= 2147483647 && ln >= -2147483648))
			return (err_print("invalid number"), NULL);
		str += move_index(str, ln);
		node->value = ln;
		node->rank = -1;
		if (*str != '\0')
			node = next_node;
	}
	if (length == 1)
		node->next = node;
	first_node->previous = node;
	return (free(next_node), node->next = first_node);
}

void	lprint(t_a *list)
{
	int		temp;

	temp = list->value;
	printf("\n%d (%d)", temp, list->rank);
	list = list->next;
	while (list->value != temp)
	{
		printf("\n%d (%d)", list->value, list->rank);
		list = list->next;
		// free(list->previous);
	}
	// free(list);
}

static int	check_tab(t_a *list, size_t length)
{
	size_t	i;
	size_t	j;
	int		value;
	t_a		*temp;

	i = 0;
	while (i < length)
	{
		value = list->value;
		// printf("\ncheck %d", value);
		j = i + 1;
		temp = list->next;
		while (j < length)
		{
			// printf(" %d", temp->value);
			if (value == temp->value)
				return (err_print("duplicate number"), 0);
			temp = temp->next;
			j++;
		}
		list = list->next;
		i++;
	}
	return (1);
}

void	free_list(t_a *list, size_t length)
{
	size_t	i;
	t_a		*temp;

	i = 0;
	while (i < length)
	{
		temp = list;
		// printf("\n\t\t%d\n", list->value);
		list = list->next;
		free(temp);
		i++;
	}
}

t_a	*check_rank(t_a *list, size_t length)
{
	int		tmp;
	int		boolean;
	size_t	i;
	int		j;
	t_a		*start;

	start = list;
	boolean = list->rank;
	j = 0;
	while (boolean == -1)
	{
		i = -1;
		while (++i < length)
			if (tmp > list->value)
				tmp = list->value;
		i = -1;
		while (++i < length)
			if (tmp == list->value)
				list->rank = j;
		j++;
	}
	return (start);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	t_a		*list;
	size_t	list_length;

	if (argc == 1)
		return (err_print("too few arguments"), 0);
	tmp = ft_jointab(&argv[1], 0, 0);
	if (!tmp)
		return (0);
	str = ft_strtrim(tmp, " ");
	list_length = ft_count_words(str, 32);
	// printf("\n|%s|\n|%s|\n|%zu|\n", str, tmp, list_length);
	list = define_a(str, list_length);
	if (!check_tab(list, list_length))
		return (free(tmp), free(str), free_list(list, list_length), 0);
	list = check_rank(list, list_length);
	lprint(list);
	free_list(list, list_length);
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
