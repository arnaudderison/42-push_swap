/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:43:32 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/17 13:49:36 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_list **stack)
{
	if (!(*stack))
		return ;
	swap(stack);
	ft_printf("sa\n");
}
void	sb(t_list **stack)
{
	if (!(*stack))
		return ;
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
