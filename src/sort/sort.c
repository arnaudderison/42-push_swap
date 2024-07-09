/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:08:53 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/09 05:08:50 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int *tab_withlst(t_stacks **stacks)
{
    int *tab;
    int i;
    t_list *nbrs;

    if (!stacks || !(*stacks) || (*stacks)->stack_a_size == 1)
        return NULL;
    tab = malloc(sizeof(int) * (*stacks)->stack_a_size);
    if (!tab)
        return NULL;
    i = 0;
    nbrs = (*stacks)->stack_a;
    while (i < (*stacks)->stack_a_size && nbrs != NULL)
    {
        tab[i++] = *(int *)nbrs->content;
        nbrs = nbrs->next;
    }
    return tab;
}

// Fonction pour partitionner le tableau
static int partition(int *tab, int start, int end)
{
    int pivot;
    int i;
    int j;
    int tmp;

    pivot = tab[end];
    i = start - 1;

    for (j = start; j < end; j++)
    {
        if (tab[j] < pivot)
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

// Fonction de tri rapide (QuickSort)
static void quicks(int *tab, int start, int end)
{
    int p;

    if (start < end)
    {
        p = partition(tab, start, end);
        quicks(tab, start, p - 1);
        quicks(tab, p + 1, end);
    }
}

// Fonction pour trier le tableau en utilisant QuickSort
static int *quick_sort(t_stacks **stacks)
{
    int *tab;

    tab = tab_withlst(stacks);
    if (!tab)
        return NULL;
    quicks(tab, 0, (*stacks)->stack_a_size - 1);
    return tab;
}


void	sort(t_stacks **stacks)
{
	int *tab;

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
		tab = quick_sort(stacks);
		maps(tab, stacks);
		quick(stacks, 0, (*stacks)->stack_a_size);
		//sort_radix(stacks);

		/*t_list	*tmp;
		int i = -1;
		tmp = (*stacks)->stack_a;
		while(++i < (*stacks)->stack_a_size){
			ft_printf("nb: %d\n", *(int*) tmp->content);
			tmp = (*stacks)->stack_a->next;
		}*/
		free(tab);
	}
}


/*A 5 6 7 1 2 8 3 0 4 

A 5 6 7 8
B 4 0 3 2 1
*/
