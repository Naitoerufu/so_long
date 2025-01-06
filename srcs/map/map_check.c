/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:29:52 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/03 15:49:49 by mmaksymi         ###   ########.fr       */
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
