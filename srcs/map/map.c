/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:28:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/22 17:00:36 by mmaksymi         ###   ########.fr       */
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
		return (print_error(ALLOC_ERR));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error(FD_ERR));
	while (++count < map->y_size)
	{
		map->map[count] = get_next_line(fd);
		if (!map->map[count])
		{
			ft_free_map(map, count);
			return (print_error(ALLOC_ERR));
		}
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
	if (ft_form_check(path, map) < 0)
		return (MAP_ERR);
	if (ft_get_map(map, path) < 0)
		return (MAP_ERR);
	if (ft_wall_check(*map) < 0)
	{
		ft_free_map(map, map->y_size);
		return (MAP_ERR);
	}
	if (ft_obj_check(map) < 0)
	{
		ft_free_map(map, map->y_size);
		return (MAP_ERR);
	}
	if (ft_map_path_check(*map) < 0)
	{
		ft_free_map(map, map->y_size);
		return (MAP_ERR);
	}
	return (1);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.y_size)
	{
		x = 0;
		while (x < game->map.x_size)
		{
			put_image(game, game->textures.grass, x * 32, y * 32);
			if (game->map.map[y][x] == 'C')
				put_image(game, game->textures.collectible, x * 32, y * 32);
			if (game->map.map[y][x] == '1')
				put_image(game, game->textures.rock, x * 32, y * 32);
			if (game->map.map[y][x] == 'P')
				put_image(game, game->textures.player_idle, x * 32, y * 32 - 8);
			if (game->map.map[y][x] == 'E')
				put_image(game, game->textures.hole, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}
