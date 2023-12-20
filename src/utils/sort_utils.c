/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:26 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 14:19:13 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	int	posmin;

	if (ft_lstsorted(&((*stacks)->stack_a)) == 0)
		return ;
	posmin = ft_lstposintmin(&((*stacks)->stack_a));
	move_min(&((*stacks)->stack_a), posmin);
	pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
	sort_three_nb(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}

void	sort_five_nb(t_stacks **stacks)
{
	int	posmin;

	if (ft_lstsorted(&((*stacks)->stack_a)) == 0)
		return ;
	posmin = ft_lstposintmin(&((*stacks)->stack_a));
	move_min(&((*stacks)->stack_a), posmin);
	if (ft_lstsorted(&((*stacks)->stack_a)) == 0)
		return ;
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	posmin = ft_lstposintmin(&((*stacks)->stack_a));
	move_min(&((*stacks)->stack_a), posmin);
	pb(&((*stacks)->stack_a), &((*stacks)->stack_b));
	sort_three_nb(&((*stacks)->stack_a));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
	pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
}

void	sort_radix(t_stacks **stacks)
{
	int	bits;
	int	bit;
	int	sizeof_stack;
	int	i;
	int	j;

	i = -1;
	bits = ft_intbit_count(ft_lstintmax(&((*stacks)->stack_a)));
	sizeof_stack = (*stacks)->stack_a_size;
	while (++i <= bits)
	{
		j = -1;
		while (++j < sizeof_stack)
		{
			bit = ((*(int *)((*stacks)->stack_a->content)) >> i) & 1;
			if (bit == 0)
				pb(&(*stacks)->stack_a, &(*stacks)->stack_b);
			else
				ra(&(*stacks)->stack_a);
		}
		while ((*stacks)->stack_b != NULL)
			pa(&((*stacks)->stack_a), &((*stacks)->stack_b));
		if (ft_lstsorted(&((*stacks)->stack_a)) == 0)
			return ;
	}
}
