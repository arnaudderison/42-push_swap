/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstposintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:50:27 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/18 14:58:10 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstposintlax(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		ret;

	tmp = (*stack);
	max = *(int *)((*stack)->content);
	i = 1;
	ret = 1;
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
