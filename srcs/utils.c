/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:19 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/01/21 14:45:50 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int print_error(int err)
{
    ft_printf("Error\n");
    if (err == ALLOC_ERR)
        ft_printf("The allocation error. Please try to restart the game\n");
    if (err == FD_ERR)
        ft_printf("The file descriptor error. Please try to restart the game\n");
    if (err == FORM_ERR)
        ft_printf("The map isn't rectangular. Please try another map\n");
    if (err == WALL_ERR)
        ft_printf("The map has an undefined border. Please try another map\n");
    if (err == OBJ_ERR)
        ft_printf("The map has an invalid object. Please try another map\n");
    if (err == EXIT_ERR)
        ft_printf("The map has more or less than one exit. Please try another map\n");
    if (err == START_ERR)
        ft_printf("The map has more or less than one starting position. Please try another map\n");
    if (err == COLLECT_ERR)
        ft_printf("The map has no collectibles. Please try another map\n");
    if (err == PATH_ERR)
        ft_printf("There is no proper path in the map. Please try another map\n");
    return (err);
}
