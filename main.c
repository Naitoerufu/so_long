/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/18 14:09:18 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	loop_hook(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.y_size)
	{
		x = 0;
		while (x < game->map.x_size)
		{
			put_image(game, game->textures.grass[0], x * 32, y * 32);
			if (game->map.map[y][x] == 'C')
				put_image(game, game->textures.collectible[0], x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	ft_form_check("map", &game.map);
	ft_get_map(&game.map, "map");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, NAME);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	load_textures(&game);
	mlx_hook(game.win, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	free_textures(&game);
	ft_free_map(&game.map);
	mlx_destroy_image(game.mlx, game.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
