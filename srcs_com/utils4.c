/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:52:51 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/15 17:52:54 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	while ((nptr[i] == '\t') || (nptr[i] == '\n') || (nptr[i] == '\r')
		|| (nptr[i] == '\v') || (nptr[i] == ' ') || (nptr[i] == '\f'))
		i++;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if ((nptr[i + 1] == '-') || (nptr[i + 1] == '+'))
			return (0);
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}

int	count_line(int fd, char *str)
{
	int	y;

	y = 0;
	while (get_next_line(fd, &str))
	{
		if (*str)
			y++;
		free(str);
	}
	free(str);
	y++;
	close(fd);
	return (y);
}
