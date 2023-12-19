/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_move_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:29:39 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/18 15:13:09 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_max(t_list **stack, int pos)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack);
	if (pos < stack_size / 2)
	{
		while (pos--)
			ra(stack);
	}
	else
	{
		pos = stack_size - pos + 1;
		while (pos--)
			rra(stack);
	}
}
