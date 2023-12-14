/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:26 by acroue            #+#    #+#             */
/*   Updated: 2023/12/14 15:20:36 by acroue           ###   ########.fr       */
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

void	free_list(t_a *list, size_t length)
{
	size_t	i;
	t_a		*temp;

	i = 0;
	if (!list)
		return ;
	printf("\nfree");
	while (i < length)
	{
		temp = list;
		printf(", %d", list->value);
		list = list->next;
		free(temp);
		i++;
	}
	printf("\n");
}

t_a	*add_back(t_a **list, t_a **end)
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
	*end = node;
	return (node);
}

t_a	*def_first(void)
{
	t_a	*node;

	node = malloc(sizeof(t_a));
	if (!node)
		return (NULL);
	node->previous = node;
	node->next = node;
	node->rank = -1;
	return (node);
}

t_a	*define_a(char *str, size_t length)
{
	long	ln;
	t_a		*node;
	t_a		*head;
	size_t	i;

	i = 0;
	node = def_first();
	if (!node)
		return (rprint("malloc failed"), NULL);
	head = node;
	while (i++ < length)
	{
		ln = ft_atol(str);
		if (!(ln <= INT_MAX && ln >= INT_MIN))
			return (rprint("invalid number"), free_list(head, i), NULL);
		if (i > 1 && !add_back(&head, &node))
			return (free_list(head, i), NULL);
		node->value = ln;
		str += move_index(str, ln);
	}
	// lprint(head);
	return (head);
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

static int	check_tab(t_a *lst, size_t len)
{
	size_t	i;
	size_t	j;
	int		value;
	t_a		*temp;

	i = 0;
	if (!lst)
		return (0);
	while (i < len - 1) // retirer le - 1 si probleme de check
	{
		value = lst->value;
		// printf("\ncheck %d :", value);
		j = i + 1;
		temp = lst->next;
		while (j < len)
		{
			// printf(" %d", temp->value);
			if (value == temp->value)
				return (rprint("duplicate number"), free_list(lst, len), 0);
			temp = temp->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (1);
}

int	find_smallest_int(t_a *list, size_t length)
{
	size_t	i;
	int		tmp;

	tmp = list->value;
	list = list->next;
	i = 0;
	while (i++ < length)
	{
		// printf("\n%d:%d\t%d\n", tmp, list->value, list->rank);
		// if (tmp > list->value && list->rank == -1)
			// printf("\n\t\t%d\n", tmp);
		if (tmp > list->value && list->rank == -1)
			tmp = list->value;
		list = list->next;
	}
	// printf("\n%d < ici temp\n", tmp);
	return (tmp);
}

t_a	*check_rank(t_a *list, size_t length)
{
	size_t	i;
	size_t	j;
	int		tmp;
	t_a		*start;

	start = list;
	i = 0;
	while (i < length)
	{
		tmp = find_smallest_int(list, length);
		j = 0;
		while (j < length)
		{
			if (tmp == list->value)
			{
				// printf("rank %d\n", tmp);
				list->rank = ++i;
			}
			list = list->next;
			j++;
		}
	}
	return (start);
}

t_a	*push(t_a *src, t_a *dest)
{
	
}

t_a	*move_b(t_a *list, size_t length)
{
	size_t	i;

	i = 0;
	while ((length - i) > 3 && i < (length / 2))
	{
		if (list->rank < (length / 2))
		{
			//push vers b
			i++;
		}
		else
		{
			list = list->next; // faire RA
		}
	}
	while (i < length)
	{
		//push vers b
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	t_a		*list;
	size_t	list_length;

	if (argc == 1)
		return (rprint("too few arguments"), 0);
	tmp = ft_jointab(&argv[1], 0, 0);
	if (!tmp)
		return (0);
	str = ft_strtrim(tmp, " ");
	list_length = ft_count_words(str, 32);
	// printf("\n|%s|\n|%s|\n|%zu|\n", str, tmp, list_length);
	list = define_a(str, list_length);
	if (!check_tab(list, list_length))
		return (free(tmp), free(str), 0);
	move_b(check_rank(list, list_length), list_length);
	lprint(list);
	free_list(list, list_length);
	return (free(tmp), free(str), 0);
}

void	rprint(char *str)
{
	write(2, "Error : ", 9);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
// ne pas oublier de retirer cette ligne dans le rprint
//
// modifier exit si argc == 1
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
//
// proteger les mallocs de define_a
