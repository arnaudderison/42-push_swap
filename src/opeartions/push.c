/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:36:47 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 00:59:36 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	new;

	if (stack_full(dest))
		return ;
	new = next_up(dest, dest->top);
	dest->stack[new] = src->stack[src->top];
	dest->top = new;
	src->top = next_down(src, src->top);
}
void	push_a(t_ps *data)
{
	push(&data->b, &data->a);
	if (data->writing)
		save_op(data, pa);
}

void	push_b(t_ps *data)
{
	push(&data->a, &data->b);
	if (data->writing)
		save_op(data, pb);
}
