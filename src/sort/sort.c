/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:08:53 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/07 19:09:26 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
//ajouter une fonction qui trie une stack

static int *tab_withlst(t_stacks **stacks)
{
	int *tab;
	int i;
	int nb;
	t_list *nbrs;

	if (!stacks || !(*stacks) || (*stacks)->stack_a_size == 1)
		return NULL;
	tab = malloc(sizeof(int) * (*stacks)->stack_a_size);
	if(!tab)
		return NULL;
	i = -1;
	nbrs = (*stacks)->stack_a;
	while(++i < (*stacks)->stack_a_size)
	{
		nb = *(int*) nbrs->content;
		nbrs = (*stacks)->stack_a->next;
		tab[i] = nb;
	}
	return tab; //free this
}

static int partition(int *tab, int start, int end)
{
	int pivot;
	int i;
	int j;
	int tmp;

	pivot = tab[end];
	i = start - 1;
	j = start - 1;

	while(++j < end)
	{
		if(tab[j] < pivot)
		{
			tmp = tab[++i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
	}
	tmp = tab[i + 1];
	tab[i + 1] = tab[end];
	tab[end] = tmp;
	return (i + 1);
}

static void quick(int *tab, int start, int end)
{
	if(start < end)
	{
		int p = partition(tab, start, end);
		quick(tab, start, p - 1);
		quick(tab, p + 1, end);
	}
}
static void quick_sort(t_stacks **stacks)
{
	int *tab;
	int i;

	tab = tab_withlst(stacks);
	if(!tab)
		return ;
	i = -1;
	while(++i < (*stacks)->stack_a_size)
		ft_printf("liste %d \n", tab[i]);
	quick(tab, 0, (*stacks)->stack_a_size - 1);
	i = -1;
	while(++i < (*stacks)->stack_a_size)
		ft_printf("liste %d \n", tab[i]);
	free(tab);
}

void	sort(t_stacks **stacks)
{
	if (!stacks || !(*stacks) || (*stacks)->stack_a_size == 1)
		return ;
	if ((*stacks)->stack_a_size == 2)
		sort_two_nb(&((*stacks)->stack_a));
	else if ((*stacks)->stack_a_size == 3)
		sort_three_nb(&((*stacks)->stack_a));
	else if ((*stacks)->stack_a_size == 4)
		sort_four_nb(stacks);
	else if ((*stacks)->stack_a_size == 5)
		sort_five_nb(stacks);
	else
	{
		if (ft_lstsorted(&((*stacks)->stack_a)) == 0)
			return ;
		sort_radix(stacks);
	}
}
