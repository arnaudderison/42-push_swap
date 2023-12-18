/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstposintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:50:27 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/18 14:06:33 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstposintlax(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		ret;

	tmp = (*stack)->next;
	max = *(int *)((*stack)->content);
	i = 2;
	while (tmp)
	{
		if (*(int *)(tmp->content) > max)
		{
			max = *(int *)(tmp->content);
			ret = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}
