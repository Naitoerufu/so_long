/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 12:43:08 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_define(t_game *game)
{
	game->map.collectible = 0;
	game->map.x_size = 0;
	game->map.y_size = 0;
	game->player.collectible_count = 0;
	game->player.moves = 0;
	game->player.x = 0;
	game->player.y = 0;
}

int	handle_input(int key, t_game *game)
{
	if (key == 97)
		ft_move_left(game);
	if (key == 100)
		ft_move_right(game);
	if (key == 119)
		ft_move_up(game);
	if (key == 115)
		ft_move_down(game);
	return (0);
}

static int	draw_map(t_game *game)
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
				put_image(game, game->textures.rock[1], x * 32, y * 32);
			if (game->map.map[y][x] == 'P')
				put_image(game, game->textures.player_idle[0], x * 32, y * 32 - 8);
			if (game->map.map[y][x] == 'E')
				put_image(game, game->textures.hole, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	ft_define(&game);
	if (!ft_map(&game.map, "maps/map.ber"))
		return (0);
	ft_define_coordinates(&game);
	game.player.collectible_count = 0;
	game.player.moves = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 32 * game.map.x_size, 32 * game.map.y_size, NAME);
	game.img = mlx_new_image(game.mlx, 32 * game.map.x_size, 32 * game.map.y_size);
	load_textures(&game);
	draw_map(&game);
	mlx_hook(game.win, 17, 0, mlx_loop_end, game.mlx);
	mlx_key_hook(game.win, handle_input, &game);
	//mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	free_textures(&game);
	ft_free_map(&game.map, game.map.y_size);
	mlx_destroy_image(game.mlx, game.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
