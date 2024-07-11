/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:51:37 by aderison          #+#    #+#             */
/*   Updated: 2024/07/11 20:45:04 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

#endif
