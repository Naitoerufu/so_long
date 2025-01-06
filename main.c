/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:59:27 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/06 17:02:16 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *to_free)
{
	int	count;

	count = -1;
	while (++count < to_free->y_size)
		free(to_free->map[count]);
	free(to_free->map);
}

int	main(int argc, char **argv)
{
	t_map test;
	(void)argc;

	ft_form_check(argv[1], &test);
	if (!ft_get_map(&test, argv[1]))
		ft_free_map(&test);
	for (int i = 0; i < test.y_size; i++)
		ft_printf("%s", test.map[i]);
	ft_printf("\n\n");
	ft_printf("\nres: %d\n", ft_map_path_check(test));
	//ft_printf("x: %d\ny: %d\n", test.x_size, test.y_size);
	ft_free_map(&test);
}