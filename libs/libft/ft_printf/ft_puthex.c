/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:52:42 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/04 13:42:52 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_length(unsigned int num)
{
	int	out;

	out = 0;
	while (num)
	{
		num /= 16;
		out++;
	}
	return (out);
}

static char	*ft_itohex(unsigned int num)
{
	int		size;
	char	*out;

	size = ft_length(num);
	out = ft_calloc(size + 1, 1);
	if (!out)
		return (NULL);
	while (num)
	{
		--size;
		out[size] = num % 16;
		if (out[size] <= 9)
			out[size] += '0';
		else
			out[size] += 55;
		num /= 16;
	}
	return (out);
}

int	ft_puthex(unsigned int num, int lowercase)
{
	char	*s;
	int		out;

	out = 0;
	s = NULL;
	if (num == 0)
		out = ft_putchar('0');
	else
	{
		s = ft_itohex(num);
		if (!s)
			return (0);
		if (lowercase > 0)
			ft_strtolower(s);
		out = ft_putstr(s);
	}
	free(s);
	return (out);
}
