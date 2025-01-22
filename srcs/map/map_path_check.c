/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:29:52 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/22 17:45:30 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_near_x_fill(t_map map, char *access_map, int i, int *flag)
{
	int	x;
	int	y;

	x = map.x_size;
	y = map.y_size;
	if (access_map[i])
	{
		if (!access_map[i - 1] && map.map[(i - 1) / x][(i - 1) % x] != '1')
		{
			access_map[i - 1] = 1;
			*flag = 1;
		}
		if (!access_map[i + 1] && map.map[(i + 1) / x][(i + 1) % x] != '1')
		{
			access_map[i + 1] = 1;
			*flag = 1;
		}
	}
}

static void	ft_near_y_fill(t_map map, char *access_map, int i, int *flag)
{
	int	x;
	int	y;

	x = map.x_size;
	y = map.y_size;
	if (access_map[i])
	{
		if (!access_map[i + x] && map.map[(i + x) / x][(i + x) % x] != '1')
		{
			access_map[i + x] = 1;
			*flag = 1;
		}
		if (!access_map[i - x] && map.map[(i - x) / x][(i - x) % x] != '1')
		{
			access_map[i - x] = 1;
			*flag = 1;
		}
	}
}

static void	ft_flood_fill(t_map map, char *access_map)
{
	int	i;
	int	flag;

	while (1)
	{
		flag = 0;
		i = -1;
		while (++i < map.x_size * map.y_size)
		{
			ft_near_x_fill(map, access_map, i, &flag);
			ft_near_y_fill(map, access_map, i, &flag);
		}
		if (!flag)
			return ;
	}
}

int	ft_map_path_check(t_map map)
{
	char	*access_map;
	int		i;

	access_map = malloc(map.x_size * map.y_size);
	if (!access_map)
		return (print_error(ALLOC_ERR));
	i = -1;
	while (++i < map.x_size * map.y_size)
		access_map[i] = map.map[i / map.x_size][i % map.x_size] == 'P';
	ft_flood_fill(map, access_map);
	i = -1;
	while (++i < map.y_size * map.x_size)
	{
		if ((map.map[i / map.x_size][i % map.x_size] == 'E' || map.map[i
				/ map.x_size][i % map.x_size] == 'C') && !access_map[i])
		{
			free(access_map);
			return (print_error(PATH_ERR));
		}
	}
	free(access_map);
	return (1);
}
