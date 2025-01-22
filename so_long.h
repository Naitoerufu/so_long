/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:00:22 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/22 16:25:04 by mmaksymi         ###   ########.fr       */
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
# define NAME "so_long"
# define ALLOC_ERR -666
# define FD_ERR -1
# define FORM_ERR -2
# define WALL_ERR -3
# define INV_OBJ_ERR -4
# define EXIT_ERR -5
# define START_ERR -6
# define COLLECT_ERR -7
# define OBJ_ERR -8
# define PATH_ERR -9
# define MAP_ERR -10

typedef struct s_map
{
	char **map;      // map
	int x_size;      // width
	int y_size;      // height
	int collectible; // quantity of the collectible objetcs on the map
}			t_map;

typedef struct s_player
{
	int x;                 // player position on the x axis
	int y;                 // player position on the y axis
	int collectible_count; // quantity of objects collected by the player
	int	moves;			// quantity of moves that player made
}			t_player;

typedef struct s_textures
{
	t_img *hole;
	t_img *rock;              // rock texture
	t_img *grass;                // grass tile texture
	t_img *collectible;          // collectible's texture
	t_img *player_idle;      // player's idle texture (R sided)
	t_img *player_idle_left; // player's idle texture (L sided)
}			t_textures;

typedef struct s_game
{
	t_img	*img;
	t_map map;           // see map struct comment
	t_player player;     // see player struct comment
	void *mlx;           // mlx pointer
	void *win;           // window pointer (also for mlx)
	t_textures textures; // see textures struct comment
}			t_game;

// MAP PART:
int			ft_form_check(char *path, t_map *map);
// checks if the map is rectangle and stocks the width and the height directly in the map's struct
int			ft_wall_check(t_map to_check);
// checks if the map has all the walls
int			ft_obj_check(t_map *to_check);
// checks if the map has the minimum objects and stocks directly their quantity in the structure
int			ft_get_map(t_map *map, char *path);
// pars the map file and stock the map in the t_map struct
int			ft_map_path_check(t_map to_check);
// checks if the map has the proper path to collect all the collectibles and to exit
int	ft_free_map(t_map *to_free, int size); // frees the map
int			ft_map(t_map *map, char *path);
// checks the errors, allocates the map and frees it in the case of a problem
int	draw_map(t_game *game); // puts the map on the screen

// GRAPHIC PART:
void		put_image(t_game *game, t_img *img, int x_pos, int y_pos);
// like mlx_put_image_to_window but better
t_img		*load(t_game *game, char *path);
// converts the xpm files in t_img
void		load_player_textures(t_game *game);
// apply the load function for all player's textures
void		load_textures(t_game *game);
// apply load function for all textures in the game
void		free_textures(t_game *game);
// free all textures in the game

// PLAYER PART:
void    ft_define_coordinates(t_game *game); //finds the player's coordinates on the map and defines them
void	ft_move_left(t_game *game); //moves the player left
void	ft_move_right(t_game *game); //moves the player right
void	ft_move_up(t_game *game); //moves the player up
void	ft_move_down(t_game *game); //moves the player down

// ERROR PART:
int print_error(int err); // checks the error's code and print the corresponding error message

#endif
