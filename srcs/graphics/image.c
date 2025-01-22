/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:46:57 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/18 14:10:19 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// static void	put_pixel(t_game *game, int x, int y, int color)
//{
//	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
//		return ;
//	((int *)game->img->data)[x * WIDTH + y] = color;
//}

static int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	return (((int *)img->data)[y * img->width + x]);
}

void	put_image(t_game *game, t_img *img, int x_pos, int y_pos)
{
	int	x;
	int	y;
	int	pixel;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = get_pixel(img, x, y);
			if (pixel != -16777216)
				mlx_pixel_put(game->mlx, game->win, x_pos + x, y_pos + y,
					pixel);
			x++;
		}
		y++;
	}
}
