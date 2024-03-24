/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:24:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/24 10:39:50 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	draw_tile(t_flood_fill *fill, t_draw_params *params, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = x * params->tile_size;
	draw_y = y * params->tile_size;
	if (fill->map[y][x] == '1')
		mlx_put_image_to_window(params->mlx, params->win, params->d->wall,
			draw_x, draw_y);
	else if (fill->map[y][x] == 'C')
		mlx_put_image_to_window(params->mlx, params->win, params->d->coins,
			draw_x, draw_y);
	else if (fill->map[y][x] == 'E')
		mlx_put_image_to_window(params->mlx, params->win, params->d->door,
			draw_x, draw_y);
	else if (fill->map[y][x] == '0')
		mlx_put_image_to_window(params->mlx, params->win, params->d->black,
			draw_x, draw_y);
	else if (fill->map[y][x] == 'P')
		mlx_put_image_to_window(params->mlx, params->win, params->d->img_player,
			draw_x, draw_y);
}

void	draw_tiles(t_flood_fill *fill, t_draw_params *params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fill->rows)
	{
		x = 0;
		while (x < fill->cols)
		{
			draw_tile(fill, params, x, y);
			x++;
			if (fill->map[y][x] == 'P')
			{
				fill->x = x;
				fill->y = y;
			}
		}
		y++;
	}
}
