/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:27:39 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/11 11:24:25 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

void	main(void)
{
	int	nb;

	nb = 2;
	ft_printf("Le nombes est %d\n", 15);
	ft_printf("%%\n");
	ft_printf("Le nombre unsigned est %u - %u - %u\n", 15, 65535, 4294967295);
	ft_printf("Le nombre 10 en hex -> %x\n", 10);
	ft_printf("Le nombre 10 en hex -> %X\n", 10);
	ft_printf("Le nombre 645 en hex -> %x\n", 645);
	ft_printf("Le nombre 98465 en hex -> %X\n", 98465);
}
