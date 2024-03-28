/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:24:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/28 06:03:11 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	move_player_right(t_flood_fill *fill, t_draw_params *params)
{
	int	prev_draw_x;
	int	prev_draw_y;
	int	draw_x;
	int	draw_y;
	int	coin;

	coin = eat_exit(fill);
	if (fill->x < fill->cols - 1 && fill->map[fill->y][fill->x + 1] != '1')
	{
		prev_draw_x = fill->x * params->tile_size;
		prev_draw_y = fill->y * params->tile_size;
		if (fill->map[fill->y][fill->x + 1] == 'E' && coin != 0)
		{
			fill->x -= 1;
		}
		mlx_put_image_to_window(params->mlx, params->win, params->d->black,
			prev_draw_x, prev_draw_y);
		fill->x += 1;
		draw_x = fill->x * params->tile_size;
		draw_y = fill->y * params->tile_size;
		mlx_put_image_to_window(params->mlx, params->win, params->d->img_player,
			draw_x, draw_y);
	}
	return ;
}

void	move_player_left(t_flood_fill *fill, t_draw_params *params)
{
	int	prev_draw_x;
	int	prev_draw_y;
	int	draw_x;
	int	draw_y;
	int	coin;

	coin = eat_exit(fill);
	if (fill->x > 0 && fill->map[fill->y][fill->x - 1] != '1')
	{
		prev_draw_x = fill->x * params->tile_size;
		prev_draw_y = fill->y * params->tile_size;
		if (fill->map[fill->y][fill->x - 1] == 'E' && coin != 0)
		{
			fill->x += 1;
		}
		mlx_put_image_to_window(params->mlx, params->win, params->d->black,
			prev_draw_x, prev_draw_y);
		fill->x -= 1;
		draw_x = fill->x * params->tile_size;
		draw_y = fill->y * params->tile_size;
		mlx_put_image_to_window(params->mlx, params->win, params->d->img_player,
			draw_x, draw_y);
	}
}

void	move_player_up(t_flood_fill *fill, t_draw_params *params)
{
	int	prev_draw_x;
	int	prev_draw_y;
	int	draw_x;
	int	draw_y;
	int	coin;

	coin = eat_exit(fill);
	if (fill->y > 0 && fill->map[fill->y - 1][fill->x] != '1')
	{
		prev_draw_x = fill->x * params->tile_size;
		prev_draw_y = fill->y * params->tile_size;
		if (fill->map[fill->y - 1][fill->x] == 'E' && coin != 0)
		{
			fill->y += 1;
		}
		mlx_put_image_to_window(params->mlx, params->win, params->d->black,
			prev_draw_x, prev_draw_y);
		fill->y -= 1;
		draw_x = fill->x * params->tile_size;
		draw_y = fill->y * params->tile_size;
		mlx_put_image_to_window(params->mlx, params->win, params->d->img_player,
			draw_x, draw_y);
	}
}

void	move_player_down(t_flood_fill *fill, t_draw_params *params)
{
	int	prev_draw_x;
	int	prev_draw_y;
	int	draw_x;
	int	draw_y;
	int	coin;

	coin = eat_exit(fill);
	if (fill->y < fill->rows - 1 && fill->map[fill->y + 1][fill->x] != '1')
	{
		prev_draw_x = fill->x * params->tile_size;
		prev_draw_y = fill->y * params->tile_size;
		if (fill->map[fill->y + 1][fill->x] == 'E' && coin != 0)
		{
			fill->y -= 1;
		}
		mlx_put_image_to_window(params->mlx, params->win, params->d->black,
			prev_draw_x, prev_draw_y);
		fill->y += 1;
		draw_x = fill->x * params->tile_size;
		draw_y = fill->y * params->tile_size;
		mlx_put_image_to_window(params->mlx, params->win, params->d->img_player,
			draw_x, draw_y);
	}
}
