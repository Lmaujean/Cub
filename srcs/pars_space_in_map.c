/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_space_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:32:20 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/14 17:32:40 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_check_last_line(t_map *game)
{
	int	size;
	int	i;
	int	j;

	size = ft_tab_len(game->total_map);
	i = size - 1;
	if (game->total_map)
	{
		j = -1;
		while (game->total_map[i][++j])
		{
			if (game->total_map[i][j] != '1' && game->total_map[i][j] != ' ')
			{
				ft_error(8, game);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_check_before_line(t_map *g, int i)
{
	int	j;

	while (g->total_map[++i])
	{
		j = -1;
		while (g->total_map[i][++j])
		{
			if ((g->total_map[i][j] == '0' || g->total_map[i][j] == 'N' || \
				g->total_map[i][j] == 'S' || g->total_map[i][j] == 'W' || \
				g->total_map[i][j] == 'E') && g->total_map[i - 1][j])
			{
				if (g->total_map[i - 1][j] != '0' && \
					g->total_map[i - 1][j] != '1' && \
					g->total_map[i - 1][j] != 'S' && \
					g->total_map[i - 1][j] != 'N' && \
					g->total_map[i - 1][j] != 'E' && \
					g->total_map[i - 1][j] != 'W')
				{
					ft_error(8, g);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

void	ft_check_next_line(t_map *g, int i)
{
	int	j;

	while (g->total_map[++i])
	{
		j = -1;
		while (g->total_map[i][++j])
		{
			if (g->total_map[i + 1] == NULL)
				break ;
			if ((g->total_map[i][j] == '0' || g->total_map[i][j] == 'N' || \
				g->total_map[i][j] == 'S' || g->total_map[i][j] == 'W' || \
				g->total_map[i][j] == 'E') && g->total_map[i + 1][j])
			{
				check_next_line(g, i, j);
			}
		}
	}
}

void	ft_check_all_file(t_map *g, int i)
{
	int	j;

	while (g->total_map[++i])
	{
		j = -1;
		while (g->total_map[i][++j])
		{
			if ((g->total_map[i][j] == '0' || g->total_map[i][j] == 'N' || \
				g->total_map[i][j] == 'S' || g->total_map[i][j] == 'W' || \
				g->total_map[i][j] == 'E') && g->total_map[i][j + 1])
			{
				if (g->total_map[i][j + 1] != '0' && \
					g->total_map[i][j + 1] != '1' && \
					g->total_map[i][j + 1] != 'S' && \
					g->total_map[i][j + 1] != 'N' && \
					g->total_map[i][j + 1] != 'E' && \
					g->total_map[i][j + 1] != 'W')
				{
					ft_error(8, g);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	ft_check_before_line(g, 0);
}

void	ft_check_first_line(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->total_map[i])
	{
		j = -1;
		while (game->total_map[i][++j])
		{
			if (game->total_map[i][j] != '1' && game->total_map[i][j] != ' ')
			{
				ft_error(8, game);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_check_next_line(game, 0);
	ft_check_last_line(game);
	ft_check_first_carac(game);
	ft_check_all_file(game, -1);
}
