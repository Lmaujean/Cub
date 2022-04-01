/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:55 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/11 10:38:59 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	ft_valid_fd(char *str, int ac)
{
	int	fd;

	if (ac != 2)
	{
		printf("Error\nArguments\n");
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error\nTry Open Directory\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFile Not Found\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_valid_file(char *str)
{
	if (!ft_check_ext(str, ".cub"))
	{
		printf("Error\nFile Not .cub\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_first_line_of_map(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '0')
			j = 0;
	}
	return (j);
}

char	**ft_get_map(int fd, const char *str, t_map *game, int i)
{
	char	*line;
	int		j;

	line = NULL;
	j = 1;
	game->total_map = malloc(sizeof(char *) * (count_line(fd, line) + 1));
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (j == 1 && *line && ft_first_line_of_map(line))
		{
			game->total_map[i++] = ft_strdup(line);
			j = 0;
		}
		else if (j == 0)
			game->total_map[i++] = ft_strdup(line);
		free(line);
	}
	game->total_map[i++] = ft_strdup(line);
	free(line);
	game->total_map[i] = NULL;
	return (game->total_map);
}

char	**ft_get_file(int fd, const char *str)
{
	char	**param;
	char	*line;
	int		i;
	int		ret;
	int		y;

	line = NULL;
	fd = open(str, O_RDONLY);
	y = count_line(fd, line);
	close(fd);
	param = malloc(sizeof(char *) * (y + 1));
	fd = open(str, O_RDONLY);
	i = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (*line)
			param[i++] = ft_strdup(line);
		free(line);
	}
	param[i] = NULL;
	close(fd);
	return (param);
}
