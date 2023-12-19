/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:08:53 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/19 16:40:07 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		ft_printf("pas encore gére\n");
}
