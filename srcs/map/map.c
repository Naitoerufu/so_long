/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:28:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/18 15:23:07 by mmaksymi         ###   ########.fr       */
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
		{
			ft_free_map(map, count);
			return (0);
		}
	}
	fd = open(path, O_RDONLY);
	count = -1;
	while (++count < map->y_size)
	{
		map->map[count] = get_next_line(fd);
	}
	return (1);
}

int	ft_free_map(t_map *to_free, int size)
{
	int	count;

	count = -1;
	while (++count < size)
		free(to_free->map[count]);
	free(to_free->map);
	return (0);
}

int	ft_map(t_map *map, char *path)
{
	if (ft_form_check(path, map) <= 0)
		return (0);
	if (!ft_get_map(map, path))
		return (0);
	map->collectible = 0;
	if (!ft_wall_check(*map))
		return (ft_free_map(map, map->y_size));
	if (!ft_obj_check(map))
		return (ft_free_map(map, map->y_size));
	if (!ft_map_path_check(*map))
		return (ft_free_map(map, map->y_size));
	return (1);
}
