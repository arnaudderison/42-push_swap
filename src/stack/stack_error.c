/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:55:10 by aderison          #+#    #+#             */
/*   Updated: 2024/07/15 21:09:15 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	error_syntax(char *av)
{
	if (av[0] != '-' && !ft_isdigit(av[0]))
		return (1);
	if (av[0] == '-' && !ft_isdigit(av[1]))
		return (1);
	while (*++av)
		if (!ft_isdigit(*av))
			return (1);
	return (0);
}

void	free_data(t_ps *data)
{
	if (data->a.stack)
		ft_free(1, &(data->a.stack));
	if (data->b.stack)
		ft_free(1, &(data->b.stack));
	if (data->operations)
		ft_lstclear(&data->operations, NULL);
}

void	check_dup(t_ps *data, int *nbr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i - 1;
		while (++j < size)
		{
			if (nbr[i] == nbr[j])
			{
				ft_free(1, &nbr);
				error(data);
			}
		}
	}
}

void	error(t_ps *data)
{
	if (data)
		free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
