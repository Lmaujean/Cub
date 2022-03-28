/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:21 by lmaujean          #+#    #+#             */
/*   Updated: 2022/02/28 11:07:23 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	empty(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (0);
	return (1);
}

int	check_param(t_check check)
{
	if (check.no.exist == 1
		&& check.so.exist == 1
		&& check.we.exist == 1
		&& check.ea.exist == 1
		&& check.f.exist == 1
		&& check.c.exist == 1)
		return (1);
	return (0);
}

void	add_in_check(t_check *check, char *str)
{
	char	**split;
	char	*line;

	split = ft_split(str, ' ');
	line = ft_strtrim(split[0], " \t");
	if (!ft_strncmp(line, "NO", 3))
		check->no.exist += 1;
	if (!ft_strncmp(line, "SO", 3))
		check->so.exist += 1;
	if (!ft_strncmp(line, "WE", 3))
		check->we.exist += 1;
	if (!ft_strncmp(line, "EA", 3))
		check->ea.exist += 1;
	if (!ft_strncmp(line, "F", 2))
		check->f.exist += 1;
	if (!ft_strncmp(line, "C", 2))
		check->c.exist += 1;
	ft_freedouble(split);
	free(line);
}

int	ft_check(char **file, t_map *game)
{
	t_check	check;
	int		i;
	char	*line;

	i = -1;
	init_check(&check);
	while (++i < ft_tab_len(file))
	{
		line = file[i];
		if (ft_strlen(line) == 0 || empty(line))
			continue ;
		add_in_check(&check, line);
		add_in_text(game, line);
	}
	if (game->text.f == NULL || game->text.c == NULL)
	{
		ft_error(9, game);
		exit(EXIT_FAILURE);
	}
	ft_check_rgb_floor(game);
	if (!check_param(check))
		return (0);
	return (1);
}

void	ft_get_param(int fd, char *str, t_map *game)
{
	char	**param;

	param = ft_get_file(fd, str);
	fd = open(str, O_RDONLY);
	game->total_map = ft_get_map(fd, str, game, 0);
	close(fd);
	if (!ft_check(param, game))
	{
		ft_freedouble(param);
		ft_error(5, game);
		exit(EXIT_FAILURE);
	}
	ft_freedouble(param);
}
