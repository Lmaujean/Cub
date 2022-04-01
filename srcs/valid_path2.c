/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:05:03 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/16 11:05:04 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_check_int_c(t_map *game)
{
	char	**split;
	int		ret;
	int		i;

	split = ft_split(game->text.c, ',');
	i = -1;
	while (split[++i])
	{
		ret = ft_atoi(split[i]);
		if (ret < 0 || ret > 255)
		{
			ft_error(9, game);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
}

void	ft_check_int_f(t_map *game)
{
	char	**split;
	int		ret;
	int		i;

	split = ft_split(game->text.f, ',');
	i = -1;
	while (split[++i])
	{
		ret = ft_atoi(split[i]);
		if (ret < 0 || ret > 255)
		{
			ft_error(9, game);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
	ft_check_int_c(game);
	valid_path_texture(game->text.no, game);
	valid_path_texture(game->text.ea, game);
	valid_path_texture(game->text.we, game);
	valid_path_texture(game->text.so, game);
}

void	valid_path_texture(char *str, t_map *game)
{
	int	fd;

	if (!ft_check_ext(str, ".xpm"))
	{
		printf("Error\nFile Not .xpm\n");
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nPath Not Valid\n");
		ft_freeallchar(game);
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error\nPath Not Valid\n");
		ft_freeallchar(game);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
