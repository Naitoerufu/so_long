/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:07 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 13:21:23 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_define_coordinates(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.y_size)
	{
		x = -1;
		while (++x < game->map.x_size)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
		}
	}
}
