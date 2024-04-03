/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:46:32 by stakhtou          #+#    #+#             */
/*   Updated: 2024/04/03 08:07:52 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	eat_exit(t_flood_fill *fill)
{
	int	coins;
	int	i;
	int	row;
	int	col;

	coins = 0;
	i = 0;
	while (i < fill->rows * fill->cols)
	{
		row = i / fill->cols;
		col = i % fill->cols;
		if (fill->map[row][col] == 'C')
			coins++;
		i++;
	}
	return (coins);
}

int	if_eat(t_flood_fill *fill, t_fp *params)
{
	int	coin;
	int	i;

	coin = eat_exit(fill);
	i = 0;
	while (coin > 0 && i < fill->rows * fill->cols)
	{
		if (fill->map[fill->y][fill->x] == 'C')
		{
			fill->map[fill->y][fill->x] = '0';
			coin--;
		}
		i++;
	}
	if (coin == 0 && fill->map[fill->y][fill->x] == 'E')
	{
		mlx_destroy_window(params->dp->mlx, params->dp->win);
		exit(1);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' || s1 == NULL)
			return (0);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ends_with_ber(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len > 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
	{
		return (1);
	}
	return (0);
}

int	close_win(t_fp *params)
{
	mlx_destroy_window(params->dp->mlx, params->dp->win);
	exit(1);
	return (1);
}
