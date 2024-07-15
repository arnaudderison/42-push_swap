/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:59:14 by aderison          #+#    #+#             */
/*   Updated: 2024/07/15 20:59:30 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_operation	stringToOp(char *str)
{
	if (!ft_strncmp(str, "pa", 2))
		return (pa);
	else if (!ft_strncmp(str, "pb", 2))
		return (pb);
	else if (!ft_strncmp(str, "rra", 3))
		return (rra);
	else if (!ft_strncmp(str, "rrb", 3))
		return (rrb);
	else if (!ft_strncmp(str, "rrr", 3))
		return (rrr);
	else if (!ft_strncmp(str, "ra", 2))
		return (ra);
	else if (!ft_strncmp(str, "rb", 2))
		return (rb);
	else if (!ft_strncmp(str, "rr", 2))
		return (rr);
	else if (!ft_strncmp(str, "sa", 2))
		return (sa);
	else if (!ft_strncmp(str, "sb", 2))
		return (sb);
	else if (!ft_strncmp(str, "ss", 2))
		return (ss);
	else
		return (null_op);
}
void	call_op(t_ps *data, enum e_operation op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == rra)
		reverse_a(data);
	else if (op == rrb)
		reverse_b(data);
	else if (op == rrr)
		reverse_ab(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		rotate_ab(data);
	else if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ss)
		swap_ab(data);
	else
		error(data);
}