/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:28:33 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/17 19:05:24 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*first;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	first = *stack;
	while ((tmp->next)->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	*stack = last;
	last->next = first;
}
