/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:07:28 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 03:53:58 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_terc_size(t_info *min, t_info *mid, t_info *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	init_terc_loc(t_location loc, t_info *min, t_info *mid, t_info *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

t_stack	*loc_to_stack(t_ps *data, t_location loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}

int	find_value(t_ps *data, t_info *terc, int pos)
{
	t_location	loc;
	t_stack		*stk;
	int			i;

	loc = terc->loc;
	stk = loc_to_stack(data, loc);
	i = 0;
	if (loc == TOP_A || loc == TOP_B)
	{
		i = stk->top;
		while (pos-- > 0)
			i = next_down(stk, i);
	}
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
	{
		i = stk->bottom;
		while (pos-- > 0)
			i = next_up(stk, i);
	}
	return (stk->stack[i]);
}

int	find_max_value(t_ps *data, t_info *terc)
{
	t_stack *stk;
	t_location loc;
	int max;
	int size;
	int i;

	stk = loc_to_stack(data, terc->loc);
	loc = terc->loc;
	size = terc->size;
	max = 0;
	if (loc == TOP_A || loc == TOP_B)
		i = stk->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stk->bottom;
	while (size--)
	{
		if (stk->stack[i] > max)
			max = stk->stack[i];
		if (loc == TOP_A || loc == TOP_B)
			i = next_down(stk, i);
		else if (loc == BOTTOM_A || loc == BOTTOM_B)
			i = next_up(stk, i);
	}
	return (max);
}