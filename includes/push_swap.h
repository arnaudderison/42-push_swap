/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:46:34 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/16 21:24:36 by arnaud           ###   ########.fr       */
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

#endif