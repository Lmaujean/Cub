/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:20:06 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 12:02:41 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>

int	color(t_map *map, int x, int y)
{
	if (map->total_map[y][x] == '0')
		return (0x4B2CAB1);
	else if (map->total_map[y][x] == '1')
		return (0x00000ABA);
	else if (map->total_map[y][x] == ' ')
		return (0x00FFFFFF);
	else
		return (0x0000BFF0);
}

void	pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x <= map->win_w && y <= map->win_h))
	{
		dst = map->img.addr + (y * map->img.line_length + x
				* (map->img.bits_per_pixel / 8));
		*(int *) dst = color;
	}
}

void	tiles(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PIXEL)
	{
		j = -1;
		while (++j < PIXEL)
		{
			pixel(map, (i + x * PIXEL), (j + y * PIXEL),
				color(map, x, y));
		}
	}
	i = x;
	j = y + map->ang_btween_rays;
	
}

void	print(t_map *map)
{
//	int	x;
//	int	y;
	int	i;
	float	angle;
	float	swap;
	float	angle_inc;

	mlx_clear_window(map->vars.mlx, map->vars.win);
	map->img.img = mlx_new_image(map->vars.mlx, map->win_w, map->win_h);
	map->img.addr = mlx_get_data_addr(map->img.img,
			&map->img.bits_per_pixel, &map->img.line_length,
			&map->img.endian);
/*	x = 0;
	while (x <= map->max_x)
	{
		y = 0;
		while (y <= map->max_y)
		{
			tiles(map, x, y);
			y++;
		}
		x++;
	}*/
	angle = map->p_angle - 30;
	swap = map->ang_btween_rays;
	angle_inc = -30;
	i = 0;
	while (swap <= 60) // alias x
	{
	//	printf("\n Tour %d\n", i);
	//	printf("vertical\n");
		proto_vertical_ray_casting(map, angle);
	//	printf("horizontal\n");
		proto_horizontal_ray_casting(map, angle);
		print_rays(map, angle_inc, i++); // 2d : angle | rc : angle_inc
		swap += map->ang_btween_rays;
		angle += map->ang_btween_rays;
		angle_inc += map->ang_btween_rays;
	}
	print_map(map);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img, 0, 0);
	mlx_destroy_image(map->vars.mlx, map->img.img);
	map->i++;
}
