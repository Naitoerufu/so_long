/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:25 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/17 13:20:32 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_img	*load(t_game *game, char *path)
{
	int	no;

	return (mlx_xpm_file_to_image(game->mlx, path, &no, &no));
}

static void	free_tab(t_game *game, t_img **tab, int size)
{
	int	count;

	count = -1;
	while (++count < size)
		mlx_destroy_image(game->mlx, tab[count]);
}

void	free_textures(t_game *game)
{
	free_tab(game, game->textures.water, 3);
	free_tab(game, game->textures.collectible, 4);
	free_tab(game, game->textures.player_idle, 12);
	free_tab(game, game->textures.player_idle_left, 12);
	free_tab(game, game->textures.player_run, 8);
	free_tab(game, game->textures.player_run_left, 8);
}

void	load_textures(t_game *game)
{
	load_player_textures(game);
	game->textures.water[0] = load(game, "textures/water/0.xpm");
	game->textures.water[1] = load(game, "textures/water/1.xpm");
	game->textures.water[2] = load(game, "textures/water/2.xpm");
	game->textures.collectible[0] = load(game, "textures/collectible/0.xpm");
	game->textures.collectible[1] = load(game, "textures/collectible/1.xpm");
	game->textures.collectible[2] = load(game, "textures/collectible/2.xpm");
	game->textures.collectible[3] = load(game, "textures/collectible/3.xpm");
}
