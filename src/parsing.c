/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:03:44 by acroue            #+#    #+#             */
/*   Updated: 2023/12/10 19:28:13 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stringcheck(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			return (0);
		if (i > 0 && (s[i] == '+' || s[i] == '-') && s[i - 1] != ' ')
			return (0);
		i++;
	}
	return (i);
}

char	*ft_jointab(char **tab, size_t i, int length)
{
	size_t	n;
	char	*joined;

	while (tab[i] != NULL)
	{
		n = ft_stringcheck(tab[i]);
		if (n == 0)
			return (err_print("invalid input"), NULL);
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
