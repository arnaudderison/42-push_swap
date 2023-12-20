/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:18:43 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 13:58:03 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!stack_a || !(*stack_a)->next)
		return ;
	tmp_a = *stack_a;
	tmp_b = (*stack_a)->next;
	tmp_a->next = tmp_b->next;
	tmp_b->next = tmp_a;
	*stack_a = tmp_b;
}
