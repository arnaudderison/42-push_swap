/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstposintmin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:50:27 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/19 19:50:35 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstposintmin(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		ret;

	tmp = (*stack);
	min = *(int *)((*stack)->content);
	i = 1;
	ret = 1;
	while (tmp)
	{
		if (*(int *)(tmp->content) < min)
		{
			min = *(int *)(tmp->content);
			ret = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
