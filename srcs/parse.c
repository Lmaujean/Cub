/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:43:00 by juan              #+#    #+#             */
/*   Updated: 2022/03/16 18:46:27 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"	
#include "../inc/struct.h"	
#include "../inc/macro.h"	
#include <stdio.h>

void	check_bit_by_bit(char **total_map, t_map *n)
{
	int	y;

	y = 0;
	while (total_map[y])
	{
		check_requirements(total_map[y], y, n);
		y++;
	}
}

void	check_requirements(char *line_map, int y, t_map *n)
{
	int	x;

	x = 0;
	while (line_map[x])
	{
		elements_signal(line_map[x], x, y, n);
		x++;
	}
}

int	elements_signal(char char_map, int x, int y, t_map *n)
{
	if (char_map == 'E' || char_map == 'W'
		|| char_map == 'S' || char_map == 'N')
	{
		n->p_angle = determine_angle(char_map);
		n->p++;
		n->p_x_grid = x;
		n->p_y_grid = y;
	}
	return (0);
}

int	determine_angle(char char_map)
{
	if (char_map == 'W')
		return (180);
	if (char_map == 'N')
		return (90);
	if (char_map == 'E')
		return (360);
	if (char_map == 'S')
		return (270);
	else
		return (-1);
}
