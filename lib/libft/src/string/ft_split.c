/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:32:48 by arnaud            #+#    #+#             */
/*   Updated: 2024/07/16 16:14:32 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_word_count(const char *str, char c)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

char	*malloccpy(const char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, i + 1);
	return (result);
}

void	free_tab(char **tab)
{
	char	**pos;

	if (!tab)
		return ;
	pos = tab;
	while (*pos != NULL)
		ft_free(1, (pos++));
	ft_free(1, tab);
}

char	**ft_split(const char *s, char c)
{
	char			**result;
	unsigned int	i;
	unsigned int	strs_len;

	if (!s)
		return (NULL);
	strs_len = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (*s && *s == c)
			s++;
		result[i] = malloccpy(s, c);
		if (!result[i])
		{
			free_tab(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
	}
	result[i] = 0;
	return (result);
}
