/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:20:30 by aderison          #+#    #+#             */
/*   Updated: 2024/07/16 16:11:51 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

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
	int		top;
	int		bottom;
}			t_stack;

typedef struct s_pushswap
{
	t_stack	a;
	t_stack	b;
	t_list	*operations;
}			t_ps;

void		free_data(t_ps *data);
void		error(t_ps *data);
int			error_syntax(char *av);
void		check_dup(t_ps *data, int *nbr, int size);
void		init_data(t_ps *data, int argc, char **argv);
void		init_stack(t_ps *data, t_stack *stk, int size);
void		fill_stack(t_ps *data, t_stack *stk, char **argv);
void		add_ope(t_ps *data, t_ope ope);
void		print_ope(t_list *head);
const char	*op_to_str(t_ope ope);
t_ope		op_from(t_list *node);
int			current_size(t_stack *stk);
int			stack_full(t_stack *stk);
int			next_down(t_stack *stk, int pos);
int			next_up(t_stack *stk, int pos);
int			value(t_stack *stk, int pos);
void		rotate_a(t_ps *data);
void		rotate_b(t_ps *data);
void		rotate_ab(t_ps *data);
void		push_a(t_ps *data);
void		push_b(t_ps *data);
void		reverse_a(t_ps *data);
void		reverse_b(t_ps *data);
void		reverse_ab(t_ps *data);
void		swap_a(t_ps *data);
void		swap_b(t_ps *data);
void		swap_ab(t_ps *data);
void		nbr_to_rank(int *nbr, int *rank, int size);
#endif
