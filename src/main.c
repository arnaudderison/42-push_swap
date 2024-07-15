/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:56 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 05:24:57 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_ps	data;
	int		is_split;

	if (argc <= 1 || !argv || !*argv)
		return (ft_putendl_fd("Error", 2), 0);
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
	if (is_split > 0)
		ft_free_matrice(1, &argv);
	if (argc < 3)
		return (free_data(&data), 0);
	sort(&data);
	print_ope(data.operations);
	return (free_data(&data), exit(EXIT_SUCCESS), 0);
}
