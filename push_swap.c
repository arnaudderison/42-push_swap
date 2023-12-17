/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:34 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/17 18:51:14 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	ft_is_validate(t_list *list, int nbr)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (*(int *)(tmp->content) == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	*atoi_malloc(char *nbr)
{
	int	*nb;
	int	i;

	i = -1;
	while (nbr[++i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (NULL);
	}
	nb = malloc(sizeof(int));
	if (!nb)
		return (NULL);
	*nb = filter_atoi(nbr);
	return (nb);
}

static t_list	*ft_init(char **args, int count)
{
	int		i;
	t_list	*ret;
	t_list	*tmp;
	int		*nbr;

	if (count == 2)
		i = 0;
	else
		i = 1;
	ret = NULL;
	while (args[i])
	{
		nbr = atoi_malloc(args[i]);
		if (!nbr)
			return (NULL);
		if (!ft_is_validate(ret, *nbr) || !nbr)
			return (NULL);
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&ret, tmp);
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], 32);
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
	reverse_rotate(&(stacks->stack_a));
	ft_printf("\n##########Termined##########\n");
	return (0);
}
