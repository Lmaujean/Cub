/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:03:59 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:03:29 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include <stdio.h>

int	keycode_management(int keycode, t_map *map)
{
	int	old_p_y;
	int	old_p_x;

	old_p_y = 0;
	old_p_x = 0;
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == LEFT_ARROW
		|| keycode == RIGHT || keycode == RIGHT_ARROW
		|| keycode == ESC)
	{
		if (keycode == UP)
			keycode_up(map, old_p_y);
		if (keycode == DOWN)
			keycode_down(map, old_p_y);
		if (keycode == LEFT)
			keycode_left(map, old_p_x);
		if (keycode == LEFT_ARROW)
			keycode_rotate_left(map);
		if (keycode == RIGHT)
			keycode_right(map, old_p_x);
		if (keycode == RIGHT_ARROW)
			keycode_rotate_right(map);
		if (keycode == ESC)
			keycode_esc(map);
		print(map);
	}
	return (0);
}
