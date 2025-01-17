/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/17 13:20:54 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((int *)game->img->data)[x * WIDTH + y] = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	return (((int *)img->data)[x * WIDTH + y]);
}

int	loop_hook(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible[0], 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible[1], 32, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible[2], 64, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible[3], 96, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, NAME);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	load_textures(&game);
	mlx_hook(game.win, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	
	
	
	free_textures(&game);
	mlx_destroy_image(game.mlx, game.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
