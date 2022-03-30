/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:26 by juan              #+#    #+#             */
/*   Updated: 2022/03/15 21:30:22 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# elif __APPLE__
#  include <mlx.h>
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_vars	t_vars;

struct	s_vars
{
	void	*mlx;
	void	*win;
};

typedef struct s_img	t_img;

struct	s_img
{
	void	*img;
	int		img_size;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_map	t_map;

/******* STRUCTURE TEXTURE *******/

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_texture;

struct s_map
{
	t_img		img;
	t_vars		vars;
	char		*texture[6];
	t_texture	text;
	char		**total_map;
	int			max_x;
	int			max_y;
	int			win_w;
	int			win_h;
	int			p;
	int			p_y_grid;
	int			p_x_grid;
	int			p_y;
	int			p_x;
	int			p_angle;
	int			dis_from_player;
	int			mid_pro_plan_x;
	int			mid_pro_plan_y;
	float		ang_btween_rays;
	int			i;
	float		*y;
	float		*x;
	float		*y_v;
	float		*x_v;
	int			arr_length;
	int			arr_length_v;
	float		save_crash;
};


typedef struct s_param
{
	int		exist;
	char	*value;
}	t_param;

typedef struct s_check
{
	t_param		no;
	t_param		so;
	t_param		we;
	t_param		ea;
	t_param		f;
	t_param		c;
}	t_check;

/******* STRUCTURE GLOBAL DU JEU *******/

typedef struct s_game
{
	char		**map;
}				t_game;

/******* GNL *******/

char			*ft_strdup(const char *src);
char			*ft_substr(char *s, int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			free_save(char **save);
int				get_line(char **line, char **save);
int				return_l(char **line, char **save, int byte_lu);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);

/******* PARSING *******/

int				ft_valid_fd(char *str, int ac);
void			ft_valid_file(char *str);
char			**ft_get_file(int fd, const char *str);
void			check_text(int fd, t_map *game);
void			ft_get_param(int fd, char *str, t_map *game);
int				ft_check_param_file(char *str);
int				ft_comp_str(char *str, char *str2);
void			ft_one_position(t_map *game		);
void			ft_check_nbr_carac(t_map *game);
void			ft_check_carac_map(t_map *game);
void			ft_check_first_line(t_map *game);
void			ft_check_last_line(t_map *game);
void			ft_check_first_carac(t_map *game);
void			ft_check_rgb_floor(t_map *game);
void			add_in_text(t_map *game, char *str);
void			ft_check_int_f(t_map *game);
void			valid_path_texture(char *str, t_map *game);
char			**ft_get_map(int fd, const char *str, t_map *game, int i);
void			check_next_line(t_map *g, int i, int j);


/******* UTILS *******/

int				ft_error(int c, t_map *game);
int				ft_strlen(const char *str);
int				ft_check_ext(const char *file, const char *ext);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_tab_len(char **tab);
int				ft_strcomp(const char *s1, char *s2);
char			*ft_str_nospace(char *str);
int				len_str_with_space(char *str);
void			init_check(t_check *check);
char			*ft_strtrim(char *s1, char *set);
void			ft_freedouble(char **ptr);
void			init_carac(t_map *game);
int				ft_count_char(char *str, char c);
void			ft_free_texture(t_texture *text);
int				ft_strisdigit(char *str);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t count, size_t size);
int				count_line(int fd, char *str);
void			ft_save_text(t_map *game, char **file);
void			ft_freeallchar(t_map *game);
void			init_struc(t_map *game);
void			ft_free_game(t_map *game);
void			ft_player(t_map *game, int i, int j);
int				empty(char *str);
void			init_raycast(t_map *game);
void			print_doublechar(char **tab);
int				check_last_line_nul(t_map *map);
int				ft_first_line_of_map(char *str);

#endif
