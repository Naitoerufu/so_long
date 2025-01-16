/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:25 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/16 15:42:34 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_img	*load(t_game *game, char *path)
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

void	load_images(t_game *game)
{
	game->images.water[0] = load(game, "textures/water/0.xpm");
	game->images.water[1] = load(game, "textures/water/1.xpm");
	game->images.water[2] = load(game, "textures/water/2.xpm");
}

void	free_images(t_game *game)
{
	free_tab(game, game->images.water, 3);
}
