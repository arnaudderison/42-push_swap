/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:42:19 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 00:44:27 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	current_size(t_stack *stk)
{
	if ((stk->top == stk->bottom) && (stk->stack[stk->top] == 0))
		return (0);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + (stk->bottom + 1));
	else
		return (stk->bottom - stk->top + 1);
}

int	stack_full(t_stack *stk)
{
	return (stk->size == current_size(stk));
}

int	next_down(t_stack *stk, int pos)
{
	if (current_size(stk) == 0)
		return (pos);
	if (pos == stk->size - 1)
		return (0);
	else
		return (pos + 1);
}

int	next_up(t_stack *stk, int pos)
{
	if (current_size(stk) == 0)
		return (pos);
	if (pos == 0)
		return (stk->size - 1);
	else
		return (pos - 1);
}

int	value(t_stack *stk, int pos)
{
	int	i;

	i = stk->top;
	while (--pos > 0)
		i = next_down(stk, i);
	return (stk->stack[i]);
}
