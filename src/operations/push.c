/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:54:38 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 13:57:57 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
}
