/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:43:08 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/14 13:43:10 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	add_space(char **line, int space)
{
	char	*tmp;
	char	*tmp_space;

	tmp_space = ft_calloc(sizeof(char *), space + 1);
	while (space-- > 0)
		tmp_space[space] = ' ';
	tmp = ft_strjoin(*line, tmp_space);
	free(*line);
	free(tmp_space);
	*line = tmp;
}

int	size_line(t_map *game)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (game->total_map[++i])
	{
		if (ft_strlen(game->total_map[i]) > max)
			max = ft_strlen(game->total_map[i]);
	}
	return (max);
}

void	ft_check_nbr_carac(t_map *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->total_map[++i])
	{
		j = -1;
		while (game->total_map[i][++j])
		{
			if (game->total_map[i][j] == 'N' || game->total_map[i][j] == 'S' || \
				game->total_map[i][j] == 'E' || game->total_map[i][j] == 'W')
				count++;
		}
	}
	if (count > 1 || count < 1)
	{
		ft_error(7, game);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_carac(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->total_map[++i])
	{
		j = -1;
		while (game->total_map[i][++j])
		{
			if (game->total_map[i][j] != '0' && game->total_map[i][j] != '1' && \
				game->total_map[i][j] != ' ' && game->total_map[i][j] != 'N' && \
				game->total_map[i][j] != 'S' && game->total_map[i][j] != 'W' && \
				game->total_map[i][j] != 'E')
			{
				ft_error(6, game);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_check_carac_map(t_map *game)
{
	const int	size = size_line(game);
	int			z;

	ft_check_carac(game);
	z = -1;
	while (game->total_map[++z])
	{
		game->max_y++;
		add_space(&game->total_map[z], size - ft_strlen(game->total_map[z]));
		if (empty(game->total_map[z]))
		{
			ft_error(8, game);
			exit(EXIT_FAILURE);
		}
	}
	game->max_x = size;
	printf("max y == %d\n", game->max_y);
	ft_check_nbr_carac(game);
}
