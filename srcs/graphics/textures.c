/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:25 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 13:36:55 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_img	*load(t_game *game, char *path)
{
	int	no;

	return (mlx_xpm_file_to_image(game->mlx, path, &no, &no));
}
/*
static void	free_tab(t_game *game, t_img **tab, int size)
{
	int	count;

	count = -1;
	while (++count < size)
		mlx_destroy_image(game->mlx, tab[count]);
}
*/
void	free_textures(t_game *game)
{
	free(game->textures.hole);
	free(game->textures.rock);
	free(game->textures.grass);
	free(game->textures.collectible);
	free(game->textures.player_idle);
	free(game->textures.player_idle_left);
}

void	load_textures(t_game *game)
{
	game->textures.player_idle = load(game, "textures/player/right/idle/0.xpm");
	game->textures.player_idle_left = load(game, "textures/player/left/idle/0.xpm");
	game->textures.hole = load(game, "textures/tiles/hole.xpm");
	game->textures.rock = load(game, "textures/tiles/big_rock.xpm");
	game->textures.collectible = load(game, "textures/collectible/0.xpm");
	game->textures.grass = load(game, "textures/tiles/grass.xpm");
}
