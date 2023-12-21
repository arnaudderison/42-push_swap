/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:48:40 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/21 15:04:42 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*ft_init(char **args, int count)
{
	int		i;
	t_list	*ret;
	t_list	*tmp;
	int		*nbr;

	if (count == 2)
		i = 0;
	else
		i = 1;
	ret = NULL;
	while (args[i])
	{
		nbr = atoi_malloc(args[i]);
		if (!nbr)
			return (NULL);
		if (!ft_is_validate(ret, *nbr) || !nbr)
			return (NULL);
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&ret, tmp);
		i++;
	}
	return (ret);
}
