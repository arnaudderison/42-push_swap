/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:27:45 by aderison          #+#    #+#             */
/*   Updated: 2024/07/15 14:57:19 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *stk)
{
	if (stack_full(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->stack[stk->bottom] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}

void	rotate_a(t_ps *data)
{
	rotate(&data->a);
	add_ope(data, ra);
}

void	rotate_b(t_ps *data)
{
	rotate(&data->b);
	add_ope(data, rb);
}

void	rotate_ab(t_ps *data)
{
	rotate(&data->a);
	rotate(&data->b);
	add_ope(data, rr);
}
