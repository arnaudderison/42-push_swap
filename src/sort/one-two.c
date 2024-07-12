/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one-two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:19:12 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:04:34 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	basecase_two(t_ps *data, t_info *to_sort)
{
	if (to_sort->loc != TOP_A)
	{
		while (to_sort->size--)
			move_from_to(data, to_sort->loc, TOP_A);
	}
	if (value(&data->a, 1) > value(&data->a, 2))
		swap_a(data);
	to_sort->size -= 2;
}

void	basecase_one(t_ps *data, t_info *to_sort)
{
	if (to_sort->loc != TOP_A)
		move_from_to(data, to_sort->loc, TOP_A);
	to_sort->size -= 1;
}
