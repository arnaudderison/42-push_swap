/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:50:46 by aderison          #+#    #+#             */
/*   Updated: 2024/07/16 16:29:11 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "push_swap.h"

static void	read_ope(t_ps *data)
{
	char				*line;
	enum e_operation	ope;

	line = ft_strdup("");
	while (line)
	{
		line = get_next_line(0);
		ope = string_to_op(line);
		call_op(data, ope);
	}
}

int	main(int argc, char **argv)
{
	t_ps	data;
	int		is_split;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc > 2)
		++argv;
	is_split = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			++argc;
		++argc;
		++is_split;
	}
	init_data(&data, argc, argv);
	read_ope(&data);
	if (data_sorted(&data))
		ft_printf("OK");
	else
		ft_printf("KO");
	return (EXIT_SUCCESS);
}
