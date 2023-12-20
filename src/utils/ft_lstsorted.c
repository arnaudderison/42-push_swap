/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:08:06 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 13:58:23 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_lstsorted(t_list **list)
{
	t_list	*tmp;

	if (!list || !(*list))
		return (-1);
	tmp = *list;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
