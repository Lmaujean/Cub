/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:53:17 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/11 14:53:18 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_check(t_check *check)
{
	check->no.exist = 0;
	check->so.exist = 0;
	check->ea.exist = 0;
	check->we.exist = 0;
	check->f.exist = 0;
	check->c.exist = 0;
}

static int	find_char(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (find_char(set, s1[start]) && s1[start] != 0)
		start++;
	end = ft_strlen(s1);
	while (find_char(set, s1[end - 1]) && end > start)
		end--;
	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (0);
	i = 0;
	while (end > start)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

void	ft_freedouble(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = 0;
			i++;
		}
		free(ptr);
		ptr = 0;
	}
}

int	ft_count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
