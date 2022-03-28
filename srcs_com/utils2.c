/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:38:48 by lmaujean          #+#    #+#             */
/*   Updated: 2022/02/28 10:38:49 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_strlen(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[j] == '\t')
				j += 4;
			else
				j++;
			i++;
		}
	}
	return (j);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int	ft_strcomp(const char *s1, char *s2)
{
	if (s1 != s2)
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (n);
	i = 0;
	while (i < n - 1 && ((unsigned char *)s1)[i] && ((unsigned char *)s2)[i]
			&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
}
