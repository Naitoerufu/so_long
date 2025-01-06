/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_and_form_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:44:11 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/03 15:50:06 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_free_and_close(char *line, int fd)
{
	free(line);
	close(fd);
	return (0);
}

static int	ft_full_line_check(char *line)
{
	size_t	count;

	count = 0;
	while (line[count] && line[count] != '\n')
	{
		if (line[count] != '1')
			return (0);
		count++;
	}
	return (1);
}

static int	ft_middle_line_check(char **line, int fd)
{
	while (*line)
	{
		if ((*line)[ft_strlen(*line) - 1] == '\n')
		{
			if (!((*line)[0] == '1' && (*line)[ft_strlen(*line) - 2] == '1'))
				return (0);
			free(*line);
			*line = get_next_line(fd);
		}
		else
			break ;
	}
	return (1);
}

int	ft_walls_check(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	if (!ft_full_line_check(line))
		return (ft_free_and_close(line, fd));
	free(line);
	line = get_next_line(fd);
	if (!ft_middle_line_check(&line, fd))
		return (ft_free_and_close(line, fd));
	if (!ft_full_line_check(line))
		return (ft_free_and_close(line, fd));
	ft_free_and_close(line, fd);
	return (1);
}

int	ft_form_check(char *path, t_map *map)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	len = ft_strlen(line);
	map->x_size = len - 1;
	map->y_size = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (ft_strlen(line) != len))
			if (line[ft_strlen(line) - 1] == '\n')
				return (ft_free_and_close(line, fd));
		map->y_size++;
	}
	ft_free_and_close(line, fd);
	return (1);
}
