/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:51:37 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 03:53:52 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef enum location
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}				t_location;

typedef struct s_info
{
	t_location	loc;
	int			size;
}				t_info;

typedef struct s_dest
{
	t_info		min;
	t_info		mid;
	t_info		max;
}				t_dest;

void			init_terc_size(t_info *min, t_info *mid, t_info *max);
t_stack			*loc_to_stack(t_ps *data, t_location loc);
int				find_value(t_ps *data, t_info *terc, int pos);
int				find_max_value(t_ps *data, t_info *terc);
void			sort(t_ps *data);
void			quicksort(t_ps *data, t_info *to_sort);
void			basecase_two(t_ps *data, t_info *to_sort);
void			basecase_two(t_ps *data, t_info *to_sort);
void			init_terc_size(t_info *min, t_info *mid, t_info *max);
void			init_terc_loc(t_location loc, t_info *min, t_info *mid,
					t_info *max);
t_stack			*loc_to_stack(t_ps *data, t_location loc);
int				find_value(t_ps *data, t_info *terc, int pos);
int				find_max_value(t_ps *data, t_info *terc);
void			add_ope(t_ps *data, t_ope ope);
void			print_ope(t_list *head);
const char		*op_to_str(t_ope ope);
t_ope			op_from(t_list *node);
int				move_from_to(t_ps *data, t_location from, t_location to);
void			move_src_bottom(t_ps *data, t_location src, t_location dst);
void			move_src_top(t_ps *data, t_location src, t_location dst);
void			move_top_a(t_ps *data, t_location dst);
void			move_top_b(t_ps *data, t_location dst);

#endif
