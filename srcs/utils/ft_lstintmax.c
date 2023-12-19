/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstintmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:04:25 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/19 18:53:00 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstintmax(t_list **stack)
{
	t_list	*tmp;
	int		max;

	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	max = *(int *)(tmp->content);
	while (tmp && tmp->next != NULL)
	{
		if (max < *(int *)(tmp->next->content))
			max = *(int *)(tmp->next->content);
		tmp = tmp->next;
	}
	return (max);
}
