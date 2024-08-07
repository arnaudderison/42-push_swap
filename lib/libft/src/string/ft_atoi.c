/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:08:38 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/12 05:51:38 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	overflow(unsigned int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	nb;
	unsigned int	temp;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str)
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = nb;
		nb = nb * 10 + str[i++] - '0';
		if (temp > nb)
			return (overflow(temp));
	}
	nb = nb * sign;
	return ((int)nb);
}
