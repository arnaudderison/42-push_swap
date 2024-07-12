/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:06:19 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 03:56:05 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	reverse(t_stack *stk)
{
	if (stack_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

void	reverse_a(t_ps *data)
{
	reverse(&data->a);
	if (data->writing)
		save_op(data, rra);
}

void	reverse_b(t_ps *data)
{
	reverse(&data->b);
	if (data->writing)
		save_op(data, rrb);
}

void	reverse_ab(t_ps *data)
{
	reverse(&data->a);
	reverse(&data->b);
	if (data->writing)
		save_op(data, rrr);
}
