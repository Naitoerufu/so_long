/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_obj_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:46:21 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/18 15:21:22 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_obj_check(t_map *to_check)
{
	int	x;
	int	y;
	int	exit_start;

	x = -1;
	y = -1;
	exit_start = 0;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'C')
				to_check->collectible++;
			if (to_check->map[y][x] == 'E' || to_check->map[y][x] == 'P')
				exit_start++;
			if (to_check->map[y][x] != 'C' && to_check->map[y][x] != 'P'
				&& to_check->map[y][x] != 'E' && to_check->map[y][x] != '1'
				&& to_check->map[y][x] != '0')
				return (0);
		}
	}
	if (exit_start != 2 || to_check->collectible < 1)
		return (0);
	return (1);
}
