/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:28:38 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/05 16:18:55 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *strs, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char const *s, int fd);
int		ft_pointer(size_t addr);
size_t	ft_strlen(const char *str);
int		ft_putnbr_fd(int nb, int fd);
int		ft_u_putnbr_fd(unsigned int nb, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_puthex_fd(int nb, int isMaj, int fd);

#endif