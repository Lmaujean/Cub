/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2022/03/14 11:03:07 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/macro.h"
#include <unistd.h>
#include <stdlib.h>

void	free_split(char **cpy_argv)
{
	char	**tmp;

	tmp = cpy_argv;
	while (*tmp)
		free(*tmp++);
	free(cpy_argv);
}

void	error_san(int error, char *error_msg)
{
	if (error == ERREXT)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO2)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO5)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO7)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO8)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO9)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO10)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO11)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO12)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO13)
		write(2, error_msg, ft_strlen(error_msg));
	exit(0);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->total_map[i])
	{
		write(1, map->total_map[i], ft_strlen(map->total_map[i]));
		write(1, "\n", 2);
		i++;
	}
}

int	ciao(t_map *map)
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	map->vars.win = 0;
	free_split(map->total_map);
	write(1, "Ciao !\n", 7);
	exit(0);
}
