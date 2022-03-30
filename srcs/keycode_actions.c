/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:46:22 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 15:15:15 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>

void	keycode_esc(t_map *map)
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	map->vars.win = 0;
	write(1, "ESC have been used\n", 20);
	exit(0);
}

void	keycode_up(t_map *map, int old_p_y)
{
	if (map->total_map[(map->p_y - 11) / 64][map->p_x / 64] != '1')
	{
                old_p_y = map->p_y / 64;
				map->p_y -= 11;
                map->total_map[old_p_y][map->p_x / 64] = '0';
                map->total_map[map->p_y / 64][map->p_x / 64] = 'M';
	}
}

void	keycode_down(t_map *map, int old_p_y)
{
	if (map->total_map[(map->p_y + 11) / 64][map->p_x / 64] != '1')
	{
		old_p_y = map->p_y / 64;
		map->p_y += 11;
		map->total_map[old_p_y][map->p_x / 64] = '0';
		map->total_map[map->p_y / 64][map->p_x / 64] = 'M';
	}
}

void	keycode_left(t_map *map, int old_p_x)
{
	if (map->total_map[map->p_y / 64][(map->p_x - 11) / 64] != '1')
	{
		old_p_x = map->p_x / 64;
		map->p_x -= 11;
		map->total_map[map->p_y / 64][old_p_x] = '0';
		map->total_map[map->p_y / 64][map->p_x / 64] = 'M';
	}
}

void	keycode_right(t_map *map, int old_p_x)
{
	if (map->total_map[map->p_y / 64][(map->p_x + 11) / 64] != '1')
	{
		old_p_x = map->p_x / 64;
		map->p_x += 11;
		map->total_map[map->p_y / 64][old_p_x] = '0';
		map->total_map[map->p_y / 64][map->p_x / 64] = 'M';
	}
}

void	keycode_rotate_left(t_map *map)
{
	map->p_angle -= 10; 
	if (map->p_angle - 10 < 0)
		map->p_angle += 360;
}
void	keycode_rotate_right(t_map *map)
{
	map->p_angle += 10; 
	if (map->p_angle + 10 >= 360)
		map->p_angle -= 360;
}