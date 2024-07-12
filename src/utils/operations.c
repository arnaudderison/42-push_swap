/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:23:01 by aderison          #+#    #+#             */
/*   Updated: 2024/07/12 04:15:19 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	add_ope(t_ps *data, t_ope ope)
{
	t_list	*new;

	new = ft_lstnew((void *)ope);
	if (!new)
		error(data);
	ft_lstadd_back(&data->operations, new);
}

void	print_ope(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_printf("%s\n", op_to_str(op_from(reader)));
		reader = reader->next;
	}
}

const char	*op_to_str(t_ope ope)
{
	const char	*strings[12];

	strings[0] = "null_op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[ope]);
}

t_ope	op_from(t_list *node)
{
	return ((t_ope)(uintptr_t)node->content);
}
