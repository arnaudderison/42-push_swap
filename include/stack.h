/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:20:30 by aderison          #+#    #+#             */
/*   Updated: 2024/07/11 20:58:36 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

typedef enum e_operation
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}			t_ope;

typedef struct s_stack
{
	int		*stack;
	int		size;
}			t_stack;

typedef struct s_pushswap
{
	t_stack	a;
	t_stack	b;
	t_list	*operations;
}			t_ps;

void		free_data(t_ps *data);

#endif