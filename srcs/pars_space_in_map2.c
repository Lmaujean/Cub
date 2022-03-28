/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_space_in_map2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:23:39 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/15 12:23:42 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	ft_check_last_carac(t_map *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (game->total_map[++i])
	{
		size = ft_strlen(game->total_map[i]);
		j = size - 1;
		if (game->total_map[i][j])
		{
			if (game->total_map[i][j] != '1' && game->total_map[i][j] != ' ')
			{
				ft_error(8, game);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_check_first_carac(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->total_map[++i])
	{
		j = 0;
		if (game->total_map[i][j])
		{
			if (game->total_map[i][j] != '1' && game->total_map[i][j] != ' ')
			{
				ft_error(8, game);
				exit(EXIT_FAILURE);
			}
		}
	}
	ft_check_last_carac(game);
}
