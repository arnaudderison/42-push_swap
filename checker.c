/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:43 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/07 17:11:51 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispastch(char *input, t_stacks *stacks)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&(stacks->stack_a));
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&(stacks->stack_b));
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&(stacks->stack_a), &(stacks->stack_b));
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&(stacks->stack_a), &(stacks->stack_b));
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&(stacks->stack_a), &(stacks->stack_b));
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&(stacks->stack_a));
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&(stacks->stack_b));
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&(stacks->stack_a));
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&(stacks->stack_b));
}

void	exec_operations(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(STD_IN);
	while (line)
	{
		dispastch(line, stacks);
		free(line);
		line = get_next_line(STD_IN);
	}
	if (ft_lstsorted(&stacks->stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], WHITE_SPACE);
	else
		args = argv;
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!args || !stacks)
		return (-1);
	stacks->stack_a = ft_init(args, argc);
	if (!(stacks->stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	stacks->stack_b = NULL;
	stacks->stack_a_size = ft_lstsize(stacks->stack_a);
	stacks->stack_b = 0;
	exec_operations(stacks);
	return (0);
}
