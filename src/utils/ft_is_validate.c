/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:45:25 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/21 14:46:03 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_is_validate(t_list *list, int nbr)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (*(int *)(tmp->content) == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
