/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:48:40 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/07 17:36:26 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_list	*ft_init(char **args, int argc)
{
	int		i;
	t_list	*ret;
	t_list	*tmp;
	int		*nbr;

	i = 1;
	ret = NULL;
	nbr = NULL;
	tmp = NULL;
	while (i < argc)
	{
		nbr = atoi_malloc(args[i]);
		ft_printf("%d\n", *nbr);
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
