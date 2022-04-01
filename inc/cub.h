/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:47:20 by juan              #+#    #+#             */
/*   Updated: 2022/03/24 13:05:02 by operculesangu    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "struct.h"
# include "keycode_qwerty.h"
# define WALL_NORD game->text.no
# define WALL_SUD game->text.so
# define WALL_EST game->text.ea
# define WALL_WEST game->text.we
# define NBR_IMG 5

int		main(int argc, char **argv);
int		cast_img(t_map map);
int		keycode_management(int keycode, t_map *map);
void	keycode_up(t_map *map, int old_P_y, float pdx, float pdy);
void	keycode_down(t_map *map, int old_P_y, float pdx, float pdy);
void	keycode_left(t_map *map, int old_P_y, float pdx, float pdy);
void	keycode_right(t_map *map, int old_P_y, float pdx, float pdy);
void	keycode_rotate_left(t_map *map);
void	keycode_rotate_right(t_map *map);
void	keycode_esc(t_map *map);
void	free_split(char **cpy_argv);
int		ciao(t_map *map);
void	error_san(int error, char *error_msg);
void	check_bit_by_bit(char **tmp, t_map *n);
void	check_requirements(char *line_map, int y, t_map *n);
int		elements_signal(char char_map, int x, int y, t_map *n);
void	init_struct(t_map *n);
int		determine_angle(char char_map);
void	print_map(t_map *map);
void	print_moves(t_map *map);
void	print(t_map *map);
void    proto_vertical_ray_casting(t_map *map, float angle);
void    proto_horizontal_ray_casting(t_map *map, float angle);
void	print_rays(t_map *map, float angle, int i);
void	tiles(t_map *map, int x, int y);
int		color(t_map *map, int x, int y);	
void	pixel(t_map *map, int x, int y, int color);
void	end(char **str, int error, char *error_msg);

#endif
