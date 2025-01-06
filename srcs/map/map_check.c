/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:29:52 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/06 17:02:12 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_obj_check(char *path/*, t_map map*/)
{
	int		fd;
	int		exit;
	int		start;
	int		collectible;
	int		bytes_read;
	int		count;
	char	buff[256];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fd);
	exit = 0;
	start = 0;
	collectible = 0;
	bytes_read = read(fd, buff, 256);
	while (bytes_read)
	{
		count = -1;
		while (++count < bytes_read)
		{
			if (buff[count] != '1' && buff[count] != '0' && buff[count] != 'C'
				&& buff[count] != 'E' && buff[count] != 'P'
				&& buff[count] != '\n')
			{
				close(fd);
				return (0);
			}
			if (buff[count] == 'C')
				collectible++;
			if (buff[count] == 'E')
				exit++;
			if (buff[count] == 'P')
				start++;
		}
		bytes_read = read(fd, buff, 256);
	}
	close(fd);
	if (exit != 1 || start != 1 || collectible == 0)
		return (0);
	return (1);
}

int	ft_map_path_check(t_map to_check)
{
	char	*access_map;
	int	i;
	int	flag;
	
	access_map = malloc(to_check.x_size * to_check.y_size);
	if (!access_map)
		return (0);
	i = -1;
	while (++i < to_check.x_size * to_check.y_size)
		access_map[i] = to_check.map[i / to_check.x_size][i % to_check.x_size] == 'P';
	while (1)
	{
		flag = 0;
		
		i = -1;
		while (++i < to_check.x_size * to_check.y_size)
		{
			if (access_map[i])
			{
				if (!access_map[i - 1] && to_check.map[(i - 1) / to_check.x_size][(i - 1) % to_check.x_size] != '1')
				{
						access_map[i - 1] = 1;
						flag = 1;
				}
				if (!access_map[i + 1] && to_check.map[(i + 1) / to_check.x_size][(i + 1) % to_check.x_size] != '1')
				{
						access_map[i + 1] = 1;
						flag = 1;
				}
				if (!access_map[i + to_check.x_size] && to_check.map[(i + to_check.x_size) / to_check.x_size][(i + to_check.x_size) % to_check.x_size] != '1')
				{
						access_map[i + to_check.x_size] = 1;
						flag = 1;
				}
				if (!access_map[i - to_check.x_size] && to_check.map[(i - to_check.x_size) / to_check.x_size][(i - to_check.x_size) % to_check.x_size] != '1')
				{
						access_map[i - to_check.x_size] = 1;
						flag = 1;
				}
			}
		}
		if (!flag)
			break ;
	}
	i = -1;
	while (++i < to_check.y_size * to_check.x_size)
	{
		if (i % to_check.x_size == 0) ft_printf("\n");
		ft_printf("%d", access_map[i]);
		if ((to_check.map[i / to_check.x_size][i % to_check.x_size] == 'E' || to_check.map[i / to_check.x_size][i % to_check.x_size] == 'C') && !access_map[i])
		{
			free(access_map);
			return (0);
		}
	}
	free (access_map);
	return (1);
}
