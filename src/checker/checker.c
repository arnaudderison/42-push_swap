/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:50:36 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 18:13:32 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_printf("[%s] -> line of testeur", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
