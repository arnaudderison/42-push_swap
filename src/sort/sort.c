/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:08:53 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/21 15:01:21 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
