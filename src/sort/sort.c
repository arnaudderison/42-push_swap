/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 03:23:11 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 03:59:38 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *data)
{
	t_stack	stk;
	int		size;

	stk = data->a;
	size = data->a.size;
	if (size <= 1 || data_sorted(data))
		return ;
	if (size == 3)
		sort_three(data, 3);
	else
		sort_all(data);
}

static void	sort_three(t_ps *data, int max)
{
	int	*stk;

	stk = data->a.stack;
	if (stk[next_down(&data->a, data->a.top)] == max)
	{
		if (stk[data->a.top] == max - 1)
			reverse_a(data);
		else
			swap_a(data);
	}
	if (stk[data->a.top] == max)
		rotate_a(data);
	if (stk[data->a.top] > stk[next_down(&data->a, data->a.top)])
		swap_a(data);
}

static void	sort_all(t_ps *data)
{
	t_info all_data;

	all_data.loc = TOP_A;
	all_data.size = data->a.size;
	quicksort(data, &all_data);
}