/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:32:59 by aderison          #+#    #+#             */
/*   Updated: 2024/07/08 20:54:43 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_lastnb(t_stacks **stacks)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = (*stacks)->stack_a;
	while (++i < (*stacks)->stack_a_size)
		tmp = (*stacks)->stack_a->next;
	return (*(int *)tmp->content);
}

static t_list	*get_posnb(t_list *stack, int pos)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = stack;
	while (++i < pos)
		tmp = tmp->next;
	return (tmp);
}

static int	partition(t_stacks **stacks, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = get_lastnb(stacks);
	i = start - 1;
	j = start - 1;
	while (++j < end)
	{
		if (*(int *)get_posnb((*stacks)->stack_a, j)->content < pivot)
		{
			i++;
			sa(&(*stacks)->stack_a);
		}
		else
			pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
	}
	pa(&(*stacks)->stack_a, &(*stacks)->stack_b);
	return (i + 1);
}

static void	quick(t_stacks **stacks, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = partition(stacks, start, end);
		quick(stacks, start, p - 1);
		quick(stacks, p + 1, end);
	}
}
/*static void	quick_sort(t_stacks **stacks)
{
	quick(stacks, 0, (*stacks)->stack_a_size - 1);
}*/
