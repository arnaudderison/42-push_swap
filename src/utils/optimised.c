/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:17:50 by aderison          #+#    #+#             */
/*   Updated: 2024/07/09 04:39:03 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void maps(int *sorted_array, t_stacks **stacks)
{
    t_list *nbrs;
    int i;
    int size = (*stacks)->stack_a_size;

    for (int i = 0; i < size; i++)
    {
        ft_printf("%d ", sorted_array[i]);
    }
    ft_printf("\n");

    for (i = 0; i < size; i++)
    {
        nbrs = (*stacks)->stack_a;
        while (nbrs != NULL)
        {
            if (*(int *)nbrs->content == sorted_array[i])
            {
                ft_printf("OK : %d replace by %d", *(int *)nbrs->content, i);
                *(int *)nbrs->content = i;
                break;  // Sortir de la boucle dès qu'une correspondance est trouvée
            }
            nbrs = nbrs->next;
        }
    }
}

