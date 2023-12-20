/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:15:13 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 13:57:38 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
