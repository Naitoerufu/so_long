/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:41:51 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/19 13:52:44 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_move_left(t_game *game)
{
	int	x;
	int y;

	x = game->player.x;
	y = game->player.y;
	
	if (game->map.map[y][x - 1] != '1' && x - 1 > 0)
	{
		if (game->map.map[y][x - 1] == 'C')
			game->player.collectible_count++;
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = 'P';
		game->player.moves++;
		game->player.x--;
	}
}

void	ft_move_right(t_game *game)
{
	int	x;
	int y;

	x = game->player.x;
	y = game->player.y;
	
	if (game->map.map[y][x + 1] != '1' && x + 1 < game->map.x_size - 1)
	{
		if (game->map.map[y][x + 1] == 'C')
			game->player.collectible_count++;
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = 'P';
		game->player.moves++;
		game->player.x++;
	}
}

void	ft_move_up(t_game *game)
{
	int	x;
	int y;

	x = game->player.x;
	y = game->player.y;
	
	if (game->map.map[y - 1][x] != '1' && y - 1 > 0)
	{
		if (game->map.map[y - 1][x] == 'C')
			game->player.collectible_count++;
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = 'P';
		game->player.moves++;
		game->player.y--;
	}
}

void	ft_move_down(t_game *game)
{
	int	x;
	int y;

	x = game->player.x;
	y = game->player.y;
	
	if (game->map.map[y + 1][x] != '1' && y + 1 < game->map.y_size - 1)
	{
		if (game->map.map[y + 1][x] == 'C')
			game->player.collectible_count++;
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = 'P';
		game->player.moves++;
		game->player.y++;
	}
}
