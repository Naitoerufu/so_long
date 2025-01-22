/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:19 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/22 18:10:39 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_error(int err)
{
	ft_printf("Error\n");
	if (err == ALLOC_ERR)
		ft_printf("The allocation error.\n");
	if (err == FD_ERR)
		ft_printf("The file descriptor error.\n");
	if (err == FORM_ERR)
		ft_printf("The map isn't rectangular.\n");
	if (err == WALL_ERR)
		ft_printf("The map has an undefined border.\n");
	if (err == OBJ_ERR)
		ft_printf("The map has an invalid object.\n");
	if (err == EXIT_ERR)
		ft_printf("The map has more or less than one exit.\n");
	if (err == START_ERR)
		ft_printf("The map has more or less than one starting position.\n");
	if (err == COLLECT_ERR)
		ft_printf("The map has no collectibles.\n");
	if (err == PATH_ERR)
		ft_printf("There is no proper path in the map.\n");
	return (err);
}
