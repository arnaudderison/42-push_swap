/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:34 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/09 04:23:29 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;


	if (argc < 3)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}else
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
	sort(&stacks);
	if (ft_lstsorted(&stacks->stack_a) == 0)
			ft_printf("OK");
	else
		ft_printf("KO");


	t_list	*tmp;
	int i = -1;
	tmp = stacks->stack_a;
	while(++i < stacks->stack_a_size){
		ft_printf("nb: %d\n", *(int*) tmp->content);
		tmp = tmp->next;
	}
	return (0);
}