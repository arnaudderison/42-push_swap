/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:36:47 by aderison          #+#    #+#             */
/*   Updated: 2024/07/15 14:56:57 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	push(t_stack *src, t_stack *dest)
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
	add_ope(data, pa);
}

void	push_b(t_ps *data)
{
	push(&data->a, &data->b);
	add_ope(data, pb);
}
