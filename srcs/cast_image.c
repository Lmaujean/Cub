/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:24:14 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:20:17 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>
#include <math.h>

int	cast_img(t_map map)
{
	float	radians;
	float	swap;
	float	angle;
	int		i;

	i = 0;
	map.win_w = PIXEL * (map.max_x + 1);
	map.win_h = PIXEL * (map.max_y + 1);
	map.vars.mlx = mlx_init();
	map.vars.win = mlx_new_window(map.vars.mlx, map.win_w,
			map.win_h, "Cub3D");
	map.mid_pro_plan_x = 320 / 2;
	map.mid_pro_plan_y = 200 / 2;
	map.ang_btween_rays = (float)60 / (float)320;
	map.dis_from_player = 160 / tan(30 * (M_PI / 180.0));
	angle = map.p_angle - 30;
	swap = map.ang_btween_rays;
	radians = (P_FOV / 2) * (M_PI / 180.0);
	map.dis_from_player = 160 / tan(radians);
	if (map.vars.mlx && map.vars.win)
	{
		mlx_hook(map.vars.win, 2, 1L << 0, keycode_management, &map);
		mlx_hook(map.vars.win, 17, 1L << 0, ciao, &map);
		print(&map);
		mlx_loop(map.vars.mlx);
		return (0);
	}
	else
		end(map.total_map, ERRNO8, ERRMSG8);
	return (1);
}

void	proto_horizontal_ray_casting(t_map *map, float angle)
{
	float	x;
	float	y;
	float	ALPHA;
	float	increment_x;
	float	increment_y;

	y = 0;
	map->arr_length = 0;
	x = 0;
	if (map->p_angle == 360)
		map->p_angle = 0;
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
//	printf("p_y = %d && p_x = %d\n", map->p_y, map->p_x);
	ALPHA = 1 / tan(angle * (M_PI / 180));
	if (angle > 0 && angle < 180)
	{
		y = (int)(map->p_y / 64) * (64) - 0.0001;
		increment_y = -64;
		increment_x = -increment_y * ALPHA;
		x = (map->p_y - y) * ALPHA + map->p_x;
		//printf("ici\n");
	}
	else if (angle > 180 && angle < 360)
	{
		y = (int)(map->p_y / 64) * (64) + 64;
		increment_y = 64;
		increment_x = -increment_y * ALPHA;
		x = (map->p_y - y) * ALPHA + map->p_x;
		//printf("al\n");
	}
/*	if ((angle >= 320 && angle < 360) || (angle >= 0 && angle <= 40))
		x = map->p_x + (map->p_y - y);
	else
		x = (map->p_y - y) * ALPHA + map->p_x;
	printf("angle = %f && rad = %f\n", angle, ALPHA);*/
	if (x / 64 < 0)
		x = 63;
	if (x / 64 > map->max_x)
		x = map->max_x * 64;
/*	if (angle >= 0 && angle <= 180)
		increment_y = -64;
	else 
		increment_y = 64;
	if ((angle >= 320 && angle <= 360) || (angle >= 0 && angle <= 40))
		increment_x = 32 + angle;
	else if (angle >= 160 && angle <= 200)
		increment_x = -32 + angle;
	else
		increment_x = -increment_y * ALPHA;*/
//	printf("increment_x = %d / %f (ALPHA) = %d\n", 64, tan(ALPHA), increment_x);
	if (angle == 0 || angle == 180)
	{
		if (angle == 0)
		{
			x = map->max_x;
			y = map->p_y;
		}
		if (angle == 180)
		{
			x = 63;
			y = map->p_y;
		}
		increment_y = 0;
		increment_x = 0;
	}
	map->y = malloc(sizeof(int));
	map->x = malloc(sizeof(int));
	map->y[map->arr_length] = y;
	map->x[map->arr_length++] = x;
	//printf("x = %f (%d) && y = %f (%d)\n", x, (int)x / 64, y, (int)y / 64);
	//printf("i_x_h = %f && i_y_h = %f\n", increment_x, increment_y);
	while (map->total_map[(int)y / 64][(int)x / 64] == '0')
	{
//		if (x <= map->max_x)
			x += increment_x;
//		if (y <= map->max_y)
			y += increment_y;
//		printf("x = %f (%d) && y = %f (%d)\n", x, (int)x / 64, y, (int)y / 64);
		map->x[map->arr_length] = x;
		map->y[map->arr_length] = y;
		map->arr_length++;
	}
}

// -------------------------------  Impression des rayons -----------------------

void	print_rays(t_map *map, float angle, int i)
{

/*	int	i;
	int	step;
	float	dx;
	float	dy;
	float	xin;
	float	yin;
	float	xx;
	float	yy;
	float	d_v;
	float	d_h;
	i = 0;
	dx = 0;
	dy = 0;
	printf("map->p_angle = %d\n", map->p_angle);
	while (i < map->arr_length)
		i++;
//	if (map->p_angle == 90)
		d_v = sqrt((pow(map->p_x - map->x_v[map->arr_length_v - 1], 2)) + (pow(map->p_y - map->y_v[map->arr_length_v - 1], 2)));
		d_h = sqrt((pow(map->p_x - map->x[map->arr_length - 1], 2)) + (pow(map->p_y - map->y[map->arr_length - 1], 2)));
		printf("d_v = %f && d_h = %f\n", d_v, d_h);
		if (d_v <= d_h)
		{
			dx = map->p_x - map->x_v[map->arr_length_v - 1]; // N
			dy = map->p_y - map->y_v[map->arr_length_v - 1]; // N
			xx = map->x_v[map->arr_length_v - 1] - 0.5; // N;
			yy = map->y_v[map->arr_length_v - 1] - 0.5; // N
		}
		else
		{
			dx = map->p_x - map->x[map->arr_length - 1]; // N
			dy = map->p_y - map->y[map->arr_length - 1]; // N
			xx = map->x[map->arr_length - 1] - 0.5; // N;
			yy = map->y[map->arr_length - 1] - 0.5; // N
		}
//	}
	if (map->p_angle == 270)
	{
		d_v = sqrt((pow(map->x_v[map->arr_length_v - 1] - map->p_x, 2)) + (pow(map->y_v[map->arr_length_v - 1] - map->p_y, 2)));
		d_h = sqrt((pow(map->x[map->arr_length - 1] - map->p_x, 2)) + (pow(map->y[map->arr_length - 1] - map->p_y, 2)));
		if (d_v <= d_h)
		{
			dx = map->x[map->arr_length_v - 1] - map->p_x; // S
			dy = map->y[map->arr_length_v - 1] - map->p_y; // S
			xx = map->p_x + 0.5; // S
			yy = map->p_y + 0.5; // S
		}
		else
		{
			dx = map->x[map->arr_length - 1] - map->p_x; // S
			dy = map->y[map->arr_length - 1] - map->p_y; // S
			xx = map->p_x + 0.5; // S
			yy = map->p_y + 0.5; // S
		}
	}
	if (map->p_angle == 180)
	{
		d_v = sqrt((pow(map->p_x - map->x_v[map->arr_length_v - 1], 2)) + (pow(map->p_y - map->y_v[map->arr_length_v - 1], 2)));
		d_h = sqrt((pow(map->p_x - map->x[map->arr_length - 1], 2)) + (pow(map->p_y - map->y[map->arr_length - 1], 2)));
		if (d_v <= d_h)
		{
			dx = map->p_x - map->x_v[map->arr_length_v - 1]; // W
			dy = map->p_y - map->y_v[map->arr_length_v - 1]; // W
			xx = map->x_v[map->arr_length_v - 1] - 0.5; // W;
			yy = map->y_v[map->arr_length_v - 1] - 0.5; // W
		}
		else
		{
			dx = map->x[map->arr_length - 1] - map->p_x; // S
			dy = map->y[map->arr_length - 1] - map->p_y; // S
			xx = map->p_x + 0.5; // S
			yy = map->p_y + 0.5; // S
		}
	}
	if (map->p_angle == 0) 
	{
		d_v = sqrt((pow(map->p_x - map->x_v[map->arr_length_v - 1], 2)) + (pow(map->p_y - map->y_v[map->arr_length_v - 1], 2)));
		d_h = sqrt((pow(map->p_x - map->x[map->arr_length - 1], 2)) + (pow(map->p_y - map->y[map->arr_length - 1], 2)));
		if (d_v <= d_h)
		{
			dx = map->x_v[map->arr_length - 1] - map->p_x; // E
			dy = map->y_v[map->arr_length - 1] - map->p_y; // E
			xx = map->p_x + 0.5; // E
			yy = map->p_y + 0.5; // E
		}
		else
		{
			dx = map->x_v[map->arr_length_v - 1] - map->p_x; // E
			dy = map->y_v[map->arr_length_v - 1] - map->p_y; // E 
			xx = map->p_x - 0.5; // E
			yy = map->p_y - 0.5; // E
		}
	}
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	xin = dx / step;
	yin = dy / step;
//	printf("step = %d && xin = %f && yin == %f\n", step, xin, yin);
	i = 0;
	while (i < step)
	{
//		printf("xx = %f && yy = %f\n", xx, yy);
		xx += xin;
		yy += yin;
		pixel(map, xx, yy, 0x00FFFFFF);
		i++;
	}
	i = j;
	i = angle;
}*/

	float	d_v;
	float	d_h;
	float	d;
	float	ALPHA;
	float	PSH;
	float	y_axis;
	int	j;
	int	k;

	ALPHA = angle * (M_PI / 180);
	d_v = sqrt((pow(map->p_x - map->x_v[map->arr_length_v - 1], 2)) + (pow(map->p_y - map->y_v[map->arr_length_v - 1], 2)));
	d_h = sqrt((pow(map->p_x - map->x[map->arr_length - 1], 2)) + (pow(map->p_y - map->y[map->arr_length - 1], 2)));
	d = 0;
	j = 0;
	k = 0;
	if (d_v <= d_h)
		d = d_v * cos(ALPHA);
	else if (d_h < d_v)
		d = d_h * cos(ALPHA);
	PSH = 64 / d * map->dis_from_player;
	if (angle - map->ang_btween_rays == 180 || angle + map->ang_btween_rays == 180
		|| angle - map->ang_btween_rays == 0 || angle + map->ang_btween_rays == 0)
		map->save_crash = PSH;
	//printf("psh = 64 / %f * %d = %f\n", d, map->dis_from_player, PSH);
	if (angle == 0 || angle == 180)
		PSH = map->save_crash;
	y_axis = map->mid_pro_plan_y - (PSH / 2);
	//printf("i = %d && y_axis = %f\n", i, y_axis);
	while (k < y_axis)
	{
		pixel(map, i, k, 0x00156489);
		k++;
	}
	while (j < PSH)
	{
		pixel(map, i, y_axis, 0x00FFFFFF);
		y_axis++;
		j++;
		k++;
	}
	while (j <= map->max_y * 64 + 32)
	{
		pixel(map, i, y_axis, 0x00BCBD06);
		y_axis++;
		j++;
	}
}

void	proto_vertical_ray_casting(t_map *map, float angle)
{
	float	y;
	float	x;
	float	increment_x;
	float	increment_y;
	float	ALPHA;

	y = 0;
	x = 0;
	increment_y = 0;
	increment_x = 0;
	if (map->p_angle == 360)
		map->p_angle = 0;
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	ALPHA  = tan(angle * (M_PI / 180));
	map->arr_length_v = 0;
	//printf("actual_angle = %f et ALPHA = %f\n", angle, ALPHA);
	if (angle > 90 && angle < 270)
	{
		x = (int)(map->p_x / 64) * (64) - 0.0001;
		increment_x = -64;
		increment_y = -increment_x * ALPHA;
		y = (map->p_x - x) * ALPHA + map->p_y;
		//printf("ba = x = %f\n", x);
	}
	else if (angle > 270 || angle < 90)
	{
		x = (int)(map->p_x / 64) * (64) + 64;
		increment_x = 64;
		increment_y = -increment_x * ALPHA;
		y = (map->p_x - x) * ALPHA + map->p_y;
		//printf("bé : x = %f\n", x);
	}
/*	if ((angle >= 230 && angle <= 310)  || (angle >= 60 && angle <= 120))
	{
		y = map->p_y + (map->p_x - x);
		printf("bee = y = %f\n", y);
	}
	else
	{
		y = (map->p_x - x) * ALPHA + map->p_y;
		printf("boo = y = %d + (%d - %f) * %f =  %f\n", map->p_y, map->p_x, x, tan(ALPHA), y);
//	}*/
	if (y / 64 < 0)
		y = 63;
	if (y / 64 >= map->max_y)
		y = map->max_y * 64;/*
//	printf("1. y = %f + (%f - %f) * %f = %f\n", map->p_y, map->p_x, x, tan(ALPHA), (map->p_y + ((map->p_x - x) / tan(ALPHA))));
	if (angle >= 240 && angle <= 300)
		increment_y = angle;
	else if (angle >= 60 && angle <= 120)
		increment_y = angle;
	else
		increment_y = -increment_x * ALPHA;
//	printf("y = %f && x = %f\n", y, x);
//	printf("increment (float) = 64 / %f = %f\n", tan(ALPHA), 64 * tan(ALPHA));
//	printf("increment (int) = %f\n", increment_y);
//	printf("%f / 64 = %d && %f / 64 = %f\n", x, x / 64, y, y / 64);
//	printf("total_map[%d][%d] = %c\n", y / 64, x / 64, map->total_map[y/64][x/64]);*/
	if (angle == 0 || angle == 180)
	{
		if (angle == 0)
		{
			x = map->max_x;
			y = map->p_y;
		}
		if (angle == 180)
		{
			x = 63;
			y = map->p_y;
		}
		increment_y = 0;
		increment_x = 0;
	}
	map->y_v = malloc(sizeof(int));
	map->x_v = malloc(sizeof(int));
	map->y_v[map->arr_length_v] = y;
	map->x_v[map->arr_length_v++] = x;
//	printf("x = %f (%d) && y = %f (%d)\n", x, (int)x / 64, y, (int)y / 64);
	while (map->total_map[(int)y / 64][(int)x / 64] == '0')
	{
		printf("%d\n", map->total_map[(int)y / 64][(int)x / 64]);
//		if (x <= map->max_x)
			x += increment_x;
//		if (y <= map->max_y)
   			y += increment_y;
		if (y / 64 > map->max_y)
			y = map->max_y * 64;
		if (y / 64 < 0)
			y = 63;
		//printf("x = %f (%d) && y = %f (%d)\n", x, (int)x / 64, y, (int)y / 64);
		map->x_v[map->arr_length_v] = x;
		map->y_v[map->arr_length_v] = y;
		map->arr_length_v++;
	}
}
