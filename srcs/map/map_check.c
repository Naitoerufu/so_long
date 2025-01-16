/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:29:52 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/07 13:38:31 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_obj_check(t_map *to_check)
{
	int	x;
	int	y;
	int	exit;
	int	start;

	x = -1;
	y = -1;
	exit = 0;
	start = 0;
	while (++y < to_check->y_size)
	{
		x = -1;
		while (++x < to_check->x_size)
		{
			if (to_check->map[y][x] == 'C')
				to_check->collectible++;
			if (to_check->map[y][x] == 'E')
				exit++;
			if (to_check->map[y][x] == 'P')
				start++;
		}
	}
	if (exit != 1 || start != 1 || to_check->collectible < 1)
		return (0);
	return (1);
}

static void	ft_near_pos_check(t_map to_check, char *access_map, int i,
		int *flag)
{
	int	x;
	int	y;

	x = to_check.x_size;
	y = to_check.y_size;
	if (access_map[i])
	{
		if (!access_map[i - 1] && to_check.map[(i - 1) / x][(i - 1) % x] != '1')
		{
			access_map[i - 1] = 1;
			*flag = 1;
		}
		if (!access_map[i + 1] && to_check.map[(i + 1) / x][(i + 1) % x] != '1')
		{
			access_map[i + 1] = 1;
			*flag = 1;
		}
		if (!access_map[i + x] && to_check.map[(i + x) / x][(i + x)
			% to_check.x_size] != '1')
		{
			access_map[i + x] = 1;
			*flag = 1;
		}
		if (!access_map[i - x] && to_check.map[(i - x) / x][(i - x) % x] != '1')
		{
			access_map[i - x] = 1;
			*flag = 1;
		}
	}
}

int	ft_map_path_check(t_map to_check)
{
	char	*access_map;
	int		i;
	int		flag;

	access_map = malloc(to_check.x_size * to_check.y_size);
	if (!access_map)
		return (0);
	i = -1;
	while (++i < to_check.x_size * to_check.y_size)
		access_map[i] = to_check.map[i / to_check.x_size][i
			% to_check.x_size] == 'P';
	while (1)
	{
		flag = 0;
		i = -1;
		while (++i < to_check.x_size * to_check.y_size)
			ft_near_pos_check(to_check, access_map, i, &flag);
		if (!flag)
			break ;
	}
	i = -1;
	while (++i < to_check.y_size * to_check.x_size)
	{
		if (i % to_check.x_size == 0)
			ft_printf("\n");
		ft_printf("%d", access_map[i]);
		if ((to_check.map[i / to_check.x_size][i % to_check.x_size] == 'E'
				|| to_check.map[i / to_check.x_size][i
				% to_check.x_size] == 'C') && !access_map[i])
		{
			free(access_map);
			return (0);
		}
	}
	free(access_map);
	return (1);
}
