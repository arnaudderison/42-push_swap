/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:26 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/19 16:39:28 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two_nb(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	if (*(int *)(((*stack)->next)->content) < *(int *)(*stack)->content)
		sa(stack);
}

void	sort_three_nb(t_list **stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (!stack || !(*stack))
		return ;
	top = *(int *)((*stack)->content);
	middle = *(int *)(((*stack)->next)->content);
	bottom = *(int *)((((*stack)->next)->next)->content);
	if (top > middle && middle < bottom && top < bottom)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack);
}

void	sort_four_nb(t_stacks **stacks)
{
	int	posmax;

	posmax = ft_lstposintlax(&((*stacks)->stack_a));
	move_max(&((*stacks)->stack_a), posmax);
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	sort_three_nb(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}

void	sort_five_nb(t_stacks **stacks)
{
	int	posmax;

	posmax = ft_lstposintlax(&((*stacks)->stack_a));
	move_max(&((*stacks)->stack_a), posmax);
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	posmax = ft_lstposintlax(&((*stacks)->stack_a));
	move_max(&((*stacks)->stack_a), posmax);
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	sort_two_nb(&((*stacks)->stack_b));
	sort_three_nb(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}
