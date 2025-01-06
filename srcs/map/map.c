/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:28:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/03 16:14:15 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_get_map(t_map *map, char *path)
{
	int	count;
	int	fd;

	count = -1;
	map->map = malloc(sizeof(char *) * map->y_size);
	if (!map->map)
		return (0);
	while (++count < map->y_size)
	{
		map->map[count] = malloc(map->x_size + 1);
		if (!map->map[count])
			return (0);
	}
	fd = open(path, O_RDONLY);
	count = -1;
	while (++count < map->y_size)
	{
		map->map[count] = get_next_line(fd);
	}
	return (1);
}
