/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:58:06 by stakhtou          #+#    #+#             */
/*   Updated: 2024/05/11 00:39:29 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdlib.h>

void	find_player_coordinates(t_flood_fill *fill)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	while (i < fill->rows * fill->cols)
	{
		row = i / fill->cols;
		col = i % fill->cols;
		if (fill->map[row][col] == 'P')
		{
			fill->x = col;
			fill->y = row;
			return ;
		}
		i++;
	}
}

void	find_exit_coordinates(t_flood_fill *fill)
{
	fill->i = 0;
	while (fill->i < fill->rows)
	{
		fill->j = 0;
		while (fill->j < fill->cols)
		{
			if (fill->map[fill->i][fill->j] == 'E')
				return ;
			fill->j++;
		}
		fill->i++;
	}
}

int	eat_check(t_flood_fill fill)
{
	int	coins;
	int	i;
	int	row;
	int	col;

	coins = 0;
	i = 0;
	find_player_coordinates(&fill);
	flood_fill(&fill);
	i = 0;
	while (i < fill.rows * fill.cols)
	{
		row = i / fill.cols;
		col = i % fill.cols;
		if (fill.map[row][col] == 'C')
			coins++;
		i++;
	}
	if (coins == 0)
		return (1);
	return (0);
}

int	check_go(t_flood_fill *fill)
{
	int	e_row;
	int	e_col;

	find_player_coordinates(fill);
	flood_fill(fill);
	find_exit_coordinates(fill);
	e_row = fill->i;
	e_col = fill->j;
	if (e_row >= 0 && e_row < fill->rows && e_col >= 0 && e_col < fill->cols
		&& fill->map[e_row][e_col] == 'E')
	{
		if ((e_row > 0 && fill->map[e_row - 1][e_col] == '-')
			|| (e_row < fill->rows - 1 && fill->map[e_row + 1][e_col] == '-')
			|| (e_col > 0 && fill->map[e_row][e_col - 1] == '-')
			|| (e_col < fill->cols - 1 && fill->map[e_row][e_col + 1] == '-'))
			return (1);
	}
	return (0);
}

int	check_size(t_flood_fill *fill)
{
	if (fill->rows > 300 || fill->cols > 300)
	{
		return (0);
	}
	else
		return (1);
}
