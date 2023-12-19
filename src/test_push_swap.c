/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:26 by acroue            #+#    #+#             */
/*   Updated: 2023/12/19 13:59:26 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	free_list(t_a *list)
{
	t_a	*temp;
	t_a	*next;

	if (!list)
		return ;
	temp = list;
	printf("\nfree");
	list = list->next;
	while (list != temp)
	{
		printf(", %d", list->value);
		next = list->next;
		free(list);
		list = next;
	}
	printf(", %d", list->value);
	free(list);
	printf("\n");
}

void	lprint(t_a *list)
{
	int		temp;

	if (!list)
	{
		printf("\nempty list\n");
		return ;
	}
	temp = list->value;
	printf("\n%d (%d)", temp, list->rank);
	list = list->next;
	while (list->value != temp)
	{
		printf("\n%d (%d)", list->value, list->rank);
		list = list->next;
		// free(list->previous);
	}
	printf("\n");
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
				return (rprint("duplicate number"), free_list(lst), 0);
			temp = temp->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	t_a		*list;
	t_a		*b;
	size_t	list_length;
	size_t	n;

	b = NULL;
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
	list = check_rank(list, list_length);
	lprint(list);
	printf("\n\n");
	n = move_b(&list, &b, list_length);
	lprint(list);
	printf("\nB [\n");
	lprint(b);
	printf("\n]\n");
	// rotate(&list, &b, "a");
	// rotate(&list, &b, "b");
	sort_three(&list, list_length - n);
	sorting(&list, &b, n);
	lprint(list);
	printf("\nB [\n");
	lprint(b);
	printf("\n]\n");
	free_list(list);
	free_list(b);
	return (free(tmp), free(str), 0);
}

void	rprint(char *str)
{
	write(2, "Error : ", 9);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
/*	ne pas oublier de retirer cette ligne dans le rprint

	modifier exit si argc == 1

	j'ai fait une partie du parsing, les entrees sont stockees dans
	un tableau de chars, maintenant il faut le verifier et le split

	verifier si les chars ne sont pas de 0-9 ou "-+ " verifier qu'un
	moins ou un plus est bien suivi d'un nombre


	au dessus c'est fait maintenant il faut separer dans une list chainee

	note du vendredi 8/12/23, le parsing est fait mes inputs sont safes

	note du dimanche 10/12/23, verifier les duplicatas de nombres bisou

	proteger les mallocs de define_a

il faut verifier que tout se fait bien push dans B puis a nouveau dans A,
qu'il n'y a pas de probleme avec B quand on le vide

faire l'algo de tri
*/
