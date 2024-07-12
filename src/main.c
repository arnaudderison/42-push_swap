/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:56 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:21:47 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_ps	data;
	int		is_split;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc > 2)
		++argv;
	is_split = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		argv = 0;
		while (argv[argc])
			++argc;
		++argc;
		is_split = 0;
	}
	init_data(&data, argc, argv);
	if (is_split > 0)
		ft_free_matrice(1, &argv);
	if (argc < 3)
		return (free_data(&data), 0);
	sort(&data);
	print_ope(data.operations);
	return (1);
}
