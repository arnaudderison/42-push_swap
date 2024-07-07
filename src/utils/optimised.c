/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:17:50 by aderison          #+#    #+#             */
/*   Updated: 2024/07/07 19:40:16 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void maps(int *tab, t_stacks **stacks)
{
    int i;
    int j;
    t_list *nbrs;
    int nbr;

    i = -1;
    nbrs = (*stacks)->stack_a;
    while(++i < (*stacks)->stack_a_size)
    {
        nbr = *(int*) nbrs->content;
        j = -1;
        while(++j < (*stacks)->stack_a_size)
        {
            if(tab[j] == nbr)
                *(int*) nbrs->content = i;
        }
        nbrs = (*stacks)->stack_a->next;
    }
}
