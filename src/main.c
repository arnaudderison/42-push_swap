/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:56 by aderison          #+#    #+#             */
/*   Updated: 2024/07/11 21:02:04 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc > 2)
		++argv;
	if (argv == 2)
	{
		argv = ft_split(argv[0], ' ');
		argv = 0;
		while (argv[argc])
			++argc;
		++argc;
	}
	ft_printf("trop cool");
	return (1);
}
