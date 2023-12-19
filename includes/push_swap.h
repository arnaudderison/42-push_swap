/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:46:34 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/19 16:41:59 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_a_size;
	int		stack_b_size;
}			t_stacks;

int			filter_atoi(const char *str);
void		swap(t_list **stack_a);
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		push(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack);
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		reverse_rotate(t_list **stack);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);
void		sort_two_nb(t_list **stack);
void		sort(t_stacks **stacks);
void		sort_three_nb(t_list **stack);
int			ft_lstposintlax(t_list **stack);
void		sort_four_nb(t_stacks **stacks);
void		move_max(t_list **stack, int pos);
void		sort_five_nb(t_stacks **stacks);

#endif