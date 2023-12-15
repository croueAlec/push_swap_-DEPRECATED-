
typedef struct s_a
{
	int			value;
	int			rank;
	struct s_a	*next;
	struct s_a	*previous;
}	t_a;

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

t_a	*push(t_a *src, t_a *dest, char c)
{
	printf("s%c\n", c);
	src->previous->next = src->next;
	src->next->previous = src->previous;
	if (!dest)
	{
		src->next = src;
		src->previous = src;
		return (src);
	}
	src->next = dest;
	src->previous = dest->previous;
	dest->previous->next = src;
	dest->previous = src;
	return (src);
}
/* gerer le cas de vider le stack b */

t_a	*move_b(t_a *list, t_a *b, size_t length)
{
	size_t	i;

	i = 0;
	while (((length / 2) - i) > 3 && i < (length / 2))
	{
		printf("\nmedian - i: %zu\nrank: %d median: %zu\n", (length/2)-i, list->rank, (length / 2));
		if ((size_t)list->rank < (length / 2))
		{
			list = list->next;
			b = push(list->previous, b, 'b');
			i++;
		}
		else
		{
			list = list->next; // faire RA
		}
	}
	while (i < length)
	{
		list = list->next;
		b = push(list->previous, b, 'b');
		i++;
	}
	return (b);
}

// static t_a	*add_back(t_a **list, t_a **end)
// {
// 	t_a	*node;
// 	t_a	*last;

// 	node = malloc(sizeof(t_a));
// 	if (!node)
// 		return (NULL);
// 	last = (*list)->previous;
// 	node->next = (*list);
// 	node->previous = last;
// 	last->next = node;
// 	(*list)->previous = node;
// 	node->rank = -1;
// 	*end = node;
// 	return (node);
// }

// static t_a	*def_first(void)
// {
// 	t_a	*node;

// 	node = malloc(sizeof(t_a));
// 	if (!node)
// 		return (NULL);
// 	node->previous = node;
// 	node->next = node;
// 	node->rank = -1;
// 	return (node);
// }

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

int	main(int argc, char *argv[])
{
	argv[argc - 1] = NULL;
	t_a	*first;
	t_a	*test;
	t_a	*tmp;
	t_a	*b = NULL;
	int	source[10] = {30, 60, 50, 10, 90, 80, 40, 100, 20, 70};

	test = malloc(sizeof(t_a));
	if(!test)
		return (0);
	test->value = 30;
	test->rank = 3;
	first = test;
	for (size_t i = 1; i < 10; i++)
	{
		tmp = malloc(sizeof(t_a));
		if(!tmp)
			return (0);
		test->next = tmp;
		tmp->previous = test;
		tmp->value = source[i];
		tmp->rank = source[i] / 10;
		test = tmp;
	}
	tmp->next = first;
	first->previous = tmp;
	lprint(first);
	move_b(first ,b , 10);
	return (0);
}
