/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:46:45 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:22:17 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	nbr_to_rank(int *nbr, int *rank, int size)
{
	int	i;
	int	j;
	int	count_rank;

	i = -1;
	while (++i < size)
	{
		j = -1;
		count_rank = 0;
		while (++j < size)
			if (nbr[j] <= nbr[i])
				++count_rank;
		rank[i] = count_rank;
	}
}

void	init_data(t_ps *data, int argc, char **argv)
{
	--argc;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argv);
	data->writing = 1;
	data->operations = NULL;
}

void	init_stack(t_ps *data, t_stack *stk, int size)
{
	stk->stack = ft_calloc(size, sizeof(int));
	if (!stk->stack)
		free_data(data);
	stk->size = size;
	stk->top = 0;
	stk->bottom = 0;
}

void	fill_stack(t_ps *data, t_stack *stk, char **argv)
{
	int	*nbr;
	int	i;

	nbr = malloc(stk->size * sizeof(int));
	if (!nbr)
		error(data);
	i = -1;
	while (argv[++i])
	{
		if (error_syntax(argv[i]))
			error(data);
		nbr[i] = ft_atoi(argv[i]);
		if (nbr[i] == -1 && ft_strlen(argv[i]) >= 2)
			error(data);
	}
	check_dup(data, nbr, stk->size);
	nbr_to_rank(nbr, stk->stack, stk->size);
	stk->bottom = stk->size - 1;
	ft_free(1, &nbr);
}
