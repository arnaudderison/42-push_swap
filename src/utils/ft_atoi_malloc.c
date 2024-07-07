/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:46:38 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/07 16:47:52 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*atoi_malloc(char *nbr)
{
	int	*nb;
	int	i;

	i = -1;
	while (nbr[++i])
	{
		if ((nbr[i] < '0' || nbr[i] > '9') && (nbr[i] != '-' && nbr[i] != '+'))
			return (NULL);
	}
	nb = malloc(sizeof(int));
	if (!nb)
		return (NULL);
	*nb = filter_atoi(nbr);
	return (nb);
}
