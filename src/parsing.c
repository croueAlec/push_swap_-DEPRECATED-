/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:03:44 by acroue            #+#    #+#             */
/*   Updated: 2023/12/15 13:33:01 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stringcheck(char *s)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			return (0);
		if (i > 0 && (s[i] == '+' || s[i] == '-') && s[i - 1] != ' ')
			return (0);
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
		if (ft_isdigit(s[i]))
			boolean = 1;
		i++;
	}
	return (i * boolean);
}

char	*ft_jointab(char **tab, size_t i, int length)
{
	size_t	n;
	char	*joined;

	while (tab[i] != NULL)
	{
		n = ft_stringcheck(tab[i]);
		if (n == 0)
			return (rprint("invalid input"), NULL);
		length += n;
		i++;
	}
	length += i - 1;
	joined = malloc((length + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	joined[length] = '\0';
	while (length > 0)
	{
		n = ft_stringcheck(tab[--i]);
		ft_memmove(&joined[length - n], tab[i], n);
		length -= n;
		if (i)
			joined[--length] = ' ';
	}
	return (joined);
}

/* 
	Here we parse the values we get as main arguments.
	They joined and then trimmed to be interpreted by the tab_manager.

	Duplicates check is done using check_tab
 */
