/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:32:59 by aderison          #+#    #+#             */
/*   Updated: 2024/07/09 05:10:59 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*static int	get_lastnb(t_stacks **stacks)
{
	t_list	*tmp;

	tmp = (*stacks)->stack_a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (*(int *)tmp->content);
}*/

/*static int	partition(t_stacks **stacks, int start, int end)
{
	int		pivot;
	int		i;
	t_list	*tmp;
	int		j;

	pivot = get_lastnb(stacks);
	i = 0;
	j = start - 1;
	tmp = (*stacks)->stack_a;
	while (++j < end)
	{
		if (!(*stacks)->stack_a) // Vérifier que stack_a n'est pas NULL
			break;
		if (*(int *)tmp->content < pivot)
		{
			i++;
			pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
		}
		else
			ra(&(*stacks)->stack_a);
		tmp = (*stacks)->stack_a->next; // Mise à jour de tmp après chaque opération
	}
	pa(&(*stacks)->stack_a, &(*stacks)->stack_b);
	return (i + 1);
}*/

void move_elements_by_pivot(t_stacks **stacks, int pivot)
{
    int size = (*stacks)->stack_a_size;
    for (int i = 0; i < size; i++)
    {
        if (*(int *)(*stacks)->stack_a->content <= pivot)
        {
            pb(&(*stacks)->stack_a, &(*stacks)->stack_b); // Pousser vers B si inférieur ou égal au pivot
        }
        else
        {
            ra(&(*stacks)->stack_a); // Faire pivoter A si supérieur au pivot
        }
    }
}
int choose_pivot(t_stacks *stacks)
{
    t_list *current = stacks->stack_a;
    int i = 0;
    while (i < stacks->stack_a_size / 2)
    {
        current = current->next;
        i++;
    }
    return *(int *)current->content;
}

void quick(t_stacks **stacks, int start, int end)
{
	int pivot;
	//t_list *stack_b;

	pivot = choose_pivot(*stacks);
	move_elements_by_pivot(stacks, pivot);

	int left_size = (end - start + 1) / 2;
    int right_size = (end - start + 1) - left_size;

	quick(stacks, 0, left_size - 1);
    quick(stacks, 0, right_size - 1);

	 while ((*stacks)->stack_b)
    {
        pa(&(*stacks)->stack_a, &(*stacks)->stack_b);
    }
}
