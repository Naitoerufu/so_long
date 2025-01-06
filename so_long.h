/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:00:22 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/06 17:02:22 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		x_size;
	int		y_size;
	int		collectible;
}			t_map;

int			ft_form_check(char *path, t_map *map);
int			ft_walls_check(char *path);
int			ft_obj_check(char *path);
int			ft_get_map(t_map *map, char *path);
int			ft_map_path_check(t_map to_check);

#endif
