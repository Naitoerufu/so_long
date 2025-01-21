/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_obj_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:46:21 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 15:58:29 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	valid_obj_check(t_map *to_check)
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
				return (print_error(INV_OBJ_ERR));
		}
	}
	return (1);
}

static int	exit_check(t_map *to_check)
{
	int x;
	int y;
	int exit;

	y = -1;
	exit = 0;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'E')
				exit++;
		}
	}
	if (exit != 1)
		return (print_error(EXIT_ERR));
	return (1);
}

static int	start_check(t_map *to_check)
{
	int x;
	int y;
	int start;

	y = -1;
	start = 0;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'P')
				start++;
		}
	}
	if (start != 1)
		return (print_error(START_ERR));
	return (1);
}

static int	collectible_check(t_map *to_check)
{
	int x;
	int y;

	y = -1;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'C')
				to_check->collectible++;
		}
	}
	if (to_check->collectible < 1)
		return (print_error(COLLECT_ERR));
	return (1);
}

int	ft_obj_check(t_map *to_check)
{
	if (valid_obj_check(to_check) == INV_OBJ_ERR)
		return (OBJ_ERR);
	if (exit_check(to_check) == EXIT_ERR)
		return (OBJ_ERR);
	if (start_check(to_check) == START_ERR)
		return (OBJ_ERR);
	if (collectible_check(to_check) == COLLECT_ERR)
		return (OBJ_ERR);
	return (1);
}
