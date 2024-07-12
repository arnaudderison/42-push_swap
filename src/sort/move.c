/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:15:27 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:07:27 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	move_from_to(t_ps *data, t_location from, t_location to)
{
	if (from == TOP_A || from == TOP_B)
		move_src_top(data, from, to);
	else
		move_src_bottom(data, from, to);
	return (1);
}

void	move_src_bottom(t_ps *data, t_location src, t_location dst)
{
	if (src == BOTTOM_A)
	{
		reverse_a(data);
		if (dst == TOP_B || dst == BOTTOM_B)
			push_b(data);
		if (dst == BOTTOM_B)
		{
			if (data->b.top != data->b.bottom)
				rotate_b(data);
		}
	}
	else if (src == BOTTOM_B)
	{
		reverse_b(data);
		if (dst == TOP_A || dst == BOTTOM_A)
			push_a(data);
		if (dst == BOTTOM_A)
			rotate_a(data);
	}
}

void	move_src_top(t_ps *data, t_location src, t_location dst)
{
	if (src == TOP_A)
		move_top_a(data, dst);
	else if (src == TOP_B)
		move_top_b(data, dst);
}

void	move_top_a(t_ps *data, t_location dst)
{
	if (dst == TOP_B || dst == BOTTOM_B)
	{
		push_b(data);
		if (dst == BOTTOM_B)
		{
			if (data->b.top != data->b.bottom)
				rotate_b(data);
		}
	}
	if (dst == BOTTOM_A)
		rotate_a(data);
}

void	move_top_b(t_ps *data, t_location dst)
{
	if (dst == TOP_A || dst == BOTTOM_A)
	{
		push_a(data);
		if (dst == BOTTOM_A)
			rotate_a(data);
	}
	if (dst == BOTTOM_B)
	{
		if (data->b.top != data->b.bottom)
			rotate_b(data);
	}
}
