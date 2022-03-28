/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:38:35 by lmaujean          #+#    #+#             */
/*   Updated: 2022/02/28 10:38:37 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_check_ext(const char *file, const char *ext)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (len_ext > 0)
	{
		if (file[len_file] != ext[len_ext])
		{
			printf("Error\nFile Not .cub\n");
			exit(EXIT_FAILURE);
		}
		len_file--;
		len_ext--;
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}	
	return (str);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			word++;
		i++;
	}
	return (word);
}

static char	*strdupcpy(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s != c && *s)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**kherz;
	int		i;
	int		n;

	if (!s)
		return (0);
	n = count_word(s, c);
	kherz = ft_calloc(sizeof(char *), (count_word((char *)s, c) + 1));
	if (!kherz)
		return (0);
	i = 0;
	while (i < n)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			kherz[i] = strdupcpy((char *)s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	kherz[i] = NULL;
	return (kherz);
}
