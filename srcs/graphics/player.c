/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:37:41 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/17 12:08:36 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_right_idle_textures(t_game *game)
{
	game->textures.player_idle[0] = load(game,
			"textures/player/right/idle/0.xpm");
	game->textures.player_idle[1] = load(game,
			"textures/player/right/idle/1.xpm");
	game->textures.player_idle[2] = load(game,
			"textures/player/right/idle/2.xpm");
	game->textures.player_idle[3] = load(game,
			"textures/player/right/idle/3.xpm");
	game->textures.player_idle[4] = load(game,
			"textures/player/right/idle/4.xpm");
	game->textures.player_idle[5] = load(game,
			"textures/player/right/idle/5.xpm");
	game->textures.player_idle[6] = load(game,
			"textures/player/right/idle/6.xpm");
	game->textures.player_idle[7] = load(game,
			"textures/player/right/idle/7.xpm");
	game->textures.player_idle[8] = load(game,
			"textures/player/right/idle/8.xpm");
	game->textures.player_idle[9] = load(game,
			"textures/player/right/idle/9.xpm");
	game->textures.player_idle[10] = load(game,
			"textures/player/right/idle/10.xpm");
	game->textures.player_idle[11] = load(game,
			"textures/player/right/idle/11.xpm");
}

static void	load_left_idle_textures(t_game *game)
{
}

static void	load_right_run_textures(t_game *game)
{
	game->textures.player_run[0] = load(game,
			"textures/player/right/run/0.xpm");
	game->textures.player_run[1] = load(game,
			"textures/player/right/run/1.xpm");
	game->textures.player_run[2] = load(game,
			"textures/player/right/run/2.xpm");
	game->textures.player_run[3] = load(game,
			"textures/player/right/run/3.xpm");
	game->textures.player_run[4] = load(game,
			"textures/player/right/run/4.xpm");
	game->textures.player_run[5] = load(game,
			"textures/player/right/run/5.xpm");
	game->textures.player_run[6] = load(game,
			"textures/player/right/run/6.xpm");
	game->textures.player_run[7] = load(game,
			"textures/player/right/run/7.xpm");
}

static void	load_left_run_textures(t_game *game)
{
	
}

void	load_player_textures(t_game *game)
{
	load_right_idle_textures(game);
	load_left_idle_textures(game);
	load_right_run_textures(game);
	load_left_run_textures(game);
}
