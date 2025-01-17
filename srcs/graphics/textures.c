/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:25 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/17 11:51:25 by mmaksymi         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(game->mlx, tab[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	free_tab(game, game->textures.water, 3);
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
