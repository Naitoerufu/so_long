/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_and_form_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:44:11 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 15:06:26 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_free_and_close(char *line, int fd)
{
	free(line);
	close(fd);
	return (0);
}

int	ft_form_check(char *path, t_map *map)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error(FD_ERR));
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
			{
				ft_free_and_close(line, fd);
				return (print_error(FORM_ERR));
			}
		map->y_size++;
	}
	ft_free_and_close(line, fd);
	return (1);
}

static int	ft_first_last_check(t_map to_check)
{
	int	count;

	count = -1;
	while (++count < to_check.x_size)
	{
		if (to_check.map[0][count] != '1')
			return (WALL_ERR);
		if (to_check.map[to_check.y_size - 1][count] != '1')
			return (WALL_ERR);
	}
	return (1);
}

int	ft_wall_check(t_map to_check)
{
	int	count;

	if (ft_first_last_check(to_check) == WALL_ERR)
		return (print_error(WALL_ERR));
	count = 0;
	while (++count < to_check.y_size - 1)
	{
		if (to_check.map[count][0] != '1')
			return (print_error(WALL_ERR));
		if (to_check.map[count][to_check.x_size - 1] != '1')
			return (print_error(WALL_ERR));
	}
	return (1);
}
