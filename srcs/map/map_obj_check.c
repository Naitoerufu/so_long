/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_obj_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:46:21 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/19 13:34:42 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_valid_obj_check(t_map *to_check)
{
	int	x;
	int y;

	y = -1;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] != 'C' && to_check->map[y][x] != 'P'
				&& to_check->map[y][x] != 'E' && to_check->map[y][x] != '1'
				&& to_check->map[y][x] != '0')
				return (0);
		}
	}
	return (1);
}

int	ft_obj_check(t_map *to_check)
{
	int	x;
	int	y;
	int start;
	int	exit;

	x = -1;
	y = -1;
	start = 0;
	exit = 0;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'C')
				to_check->collectible++;
			if (to_check->map[y][x] == 'P')
				start++;
			if (to_check->map[y][x] == 'E')
				exit++;
		}
	}
	if (start != 1 || exit != 1 || to_check->collectible < 1 || !ft_valid_obj_check(to_check))
		return (0);
	return (1);
}
