/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:43 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:15:13 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>

void	init_struct(t_map *map)
{
	int	i;

	i = 0;
	map->total_map = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->i = 0;
	map->mid_pro_plan_x = 0;
	map->mid_pro_plan_y = 0;
	map->ang_btween_rays = 0;
	map->text.c = NULL;
	map->text.f = NULL;
	map->text.no = NULL;
	map->text.so = NULL;
	map->text.we = NULL;
	map->text.ea = NULL;
	while (i < 6)
	{
		map->texture[i] = NULL;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		fd;

	init_struct(&map);
	fd = ft_valid_fd(argv[1], argc);
	if (fd)
	{
		ft_valid_file(argv[1]);
		ft_get_param(fd, argv[1], &map);
		ft_check_carac_map(&map);
		ft_check_first_line(&map);
	}
	check_bit_by_bit(map.total_map, &map);
	map.p_x = (map.p_x_grid * 64) + 32;
	map.p_y = (map.p_y_grid * 64) + 32;
	cast_img(map);
	printf("HERE\n");
	// ft_free_game(&map);
	// free_split(map.total_map);
	return (0);
}
