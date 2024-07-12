/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:06:19 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:21:10 by aderison         ###   ########.fr       */
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
		add_ope(data, rra);
}

void	reverse_b(t_ps *data)
{
	reverse(&data->b);
	if (data->writing)
		add_ope(data, rrb);
}

void	reverse_ab(t_ps *data)
{
	reverse(&data->a);
	reverse(&data->b);
	if (data->writing)
		add_ope(data, rrr);
}
