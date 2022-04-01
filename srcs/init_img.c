/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:07:00 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/31 12:07:01 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>
#include <math.h>

static int	ft_error_failure(t_game *game)
{
	printf("Error\nFail Load Image\n");
	ft_free_game(game);
	return (EXIT_FAILURE);
}

int	ft_init_img(t_map *game)
{
	int			i;
	const char	*tab[] = {WALL_NORD, WALL_SUD, WALL_EST, WALL_WEST};

	game->img->img = ft_calloc(sizeof(t_img), NBR_IMG);
	if (!game->img->img)
		return (0);
	game->img[0].img = mlx_new_image(game->vars.mlx, 1920, 1080);
	game->img[0].addr = mlx_get_data_addr(game->img[0].img, \
	&game->img->bits_per_pixel, &game->img->line_length, \
	&game->img->endian);
	if (game->img[0].img == NULL)
		exit(ft_error_failure(game));
	i = 1;
	while (i < NBR_IMG)
	{
		game->img[i].img = mlx_xpm_file_to_image(game->vars.mlx,
				(char *)tab[i - 1], &game->img[i].width, &game->img[i].height);
		if (game->img[i].img == NULL)
			exit(ft_error_failure(game));
		i++;
	}
	return (1);
}