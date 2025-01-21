/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 15:59:18 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_define(t_game *game)
{
	game->map.collectible = 0;
	game->map.x_size = 0;
	game->map.y_size = 0;
	game->player.collectible_count = 0;
	game->player.moves = 0;
	game->player.x = 0;
	game->player.y = 0;
}

int	handle_exit(t_game *game)
{
	int x;
	int y;

	x = game->player.x;
	y = game->player.y;
	if (game->map.map[y][x] == 'E' && game->map.collectible == game->player.collectible_count)
	{
		mlx_loop_end(game->mlx);
		ft_printf("CONGRATULATIONS! THE LEVEL IS CLEARED!\n");
	}
	return (0);
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
	if (key == 65307)
		mlx_loop_end(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	ft_define(&game);
	if (!ft_map(&game.map, av[1]))
		return (MAP_ERR);
	ft_define_coordinates(&game);
	ft_printf("current moves: %d\n", game.player.moves);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 32 * game.map.x_size, 32 * game.map.y_size, NAME);
	game.img = mlx_new_image(game.mlx, 32 * game.map.x_size, 32 * game.map.y_size);
	load_textures(&game);
	draw_map(&game);
	mlx_hook(game.win, 17, 0, mlx_loop_end, game.mlx);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop_hook(game.mlx, handle_exit, &game);
	mlx_loop(game.mlx);
	free_textures(&game);
	ft_free_map(&game.map, game.map.y_size);
	mlx_destroy_image(game.mlx, game.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
