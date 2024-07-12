/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:21:20 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:12:01 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*find_pivots(int size, int max)
{
	int	*pivots;

	pivots = malloc(3 * sizeof(int));
	if (!pivots)
		return (0);
	pivots[0] = max - size + 1;
	pivots[1] = pivots[0] + size / 3;
	pivots[2] = pivots[0] + (2 * size / 3);
	return (pivots);
}

static void	data_split(t_ps *data, t_info *to_sort, t_dest *dest)
{
	int	*pivots;
	int	max;
	int	value;

	init_terc_size(&dest->min, &dest->mid, &dest->max);
	init_terc_loc(to_sort->loc, &dest->min, &dest->mid, &dest->max);
	max = find_max_value(data, to_sort);
	pivots = find_pivots(to_sort->size, max);
	if (!pivots)
		exit(EXIT_FAILURE);
	while (to_sort->size--)
	{
		value = find_value(data, to_sort, 0);
		if (value >= pivots[2])
			dest->max.size += move_from_to(data, to_sort->loc, dest->max.loc);
		else if (value >= pivots[1])
			dest->mid.size += move_from_to(data, to_sort->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_sort->loc, dest->min.loc);
	}
}

void	quicksort(t_ps *data, t_info *to_sort)
{
	t_dest	dest;

	if (to_sort->loc == BOTTOM_A && current_size(&data->a) == to_sort->size)
		to_sort->loc = TOP_A;
	if (to_sort->loc == BOTTOM_B && current_size(&data->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->size <= 2)
	{
		if (to_sort->size == 2)
			basecase_two(data, to_sort);
		if (to_sort->size == 1)
			basecase_one(data, to_sort);
		return ;
	}
	data_split(data, to_sort, &dest);
	quicksort(data, &dest.max);
	quicksort(data, &dest.mid);
	quicksort(data, &dest.min);
}
