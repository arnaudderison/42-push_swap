/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:50:36 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/20 21:00:53 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	main(int argc, char **argv)
{
	char	*line;
	char	**args;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
		args = argv;
	line = get_next_line(STD_OUT);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
