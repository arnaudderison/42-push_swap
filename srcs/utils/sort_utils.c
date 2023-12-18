/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:26 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/18 10:27:17 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	tri_two_nb(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	if (*(int *)(((*stack)->next)->content) < *(int *)(*stack)->content)
		sa(stack);
}
