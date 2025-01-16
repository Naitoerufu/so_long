/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:00:22 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:09 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
# include "libs/mlx/mlx_int.h"
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_map
{
	char		**map;
	int			x_size;
	int			y_size;
	int			collectible;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			collectible_count;
}				t_player;

typedef struct s_textures
{
	t_img		*water[3];
}				t_textures;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_textures	textures;
}				t_game;

int				ft_form_check(char *path, t_map *map);
int				ft_walls_check(char *path);
int				ft_obj_check(t_map *to_check);
int				ft_get_map(t_map *map, char *path);
int				ft_map_path_check(t_map to_check);
void			ft_free_map(t_map *to_free);

void			load_images(t_game *game);
void			free_images(t_game *game);

#endif
