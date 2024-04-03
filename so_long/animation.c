/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:58:33 by stakhtou          #+#    #+#             */
/*   Updated: 2024/04/02 13:18:34 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	init_map(t_mini *d)
{
	int	width;
	int	height;

	if (d == NULL || d->init_ptr == NULL)
		return ;
	width = 40;
	height = 40;
	d->black = load_image(d->init_ptr, "textures/black.xpm", &width, &height);
	d->wall = load_image(d->init_ptr, "textures/wall.xpm", &width, &height);
	d->coins = load_image(d->init_ptr, "textures/coin.xpm", &width, &height);
	d->door = load_image(d->init_ptr, "textures/exit.xpm", &width, &height);
	d->img_player = load_image(d->init_ptr, "textures/ball.xpm", &width,
			&height);
}

void	*load_image(void *mlx_ptr, char *path, int *width, int *height)
{
	void	*img_ptr;

	if (mlx_ptr == NULL)
	{
		return (NULL);
	}
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, width, height);
	if (img_ptr == NULL)
	{
		ft_printf("image not found");
		exit(1);
	}
	return (img_ptr);
}

int	destroy(int keycode, t_fp *params)
{
	if (keycode == 53)
	{
		mlx_destroy_window(params->dp->mlx, params->dp->win);
		exit(0);
	}
	return (1);
}

int	move_player(int keycode, t_fp *params)
{
	static int	total_moves = 0;

	if ((keycode == 13 && params->f->map[params->f->y - 1][params->f->x] != '1')
		|| (keycode == 0 && params->f->x > 0
			&& params->f->map[params->f->y][params->f->x - 1] != '1')
		|| (keycode == 1 && params->f->y < params->f->rows - 1
			&& params->f->map[params->f->y + 1][params->f->x] != '1')
		|| (keycode == 2 && params->f->x < params->f->cols - 1
			&& params->f->map[params->f->y][params->f->x + 1] != '1'))
	{
		if (keycode == 13)
			move_player_up(params->f, params->dp, &total_moves);
		else if (keycode == 0)
			move_player_left(params->f, params->dp, &total_moves);
		else if (keycode == 1)
			move_player_down(params->f, params->dp, &total_moves);
		else if (keycode == 2)
			move_player_right(params->f, params->dp, &total_moves);
	}
	if_eat(params->f, params);
	destroy(keycode, params);
	return (0);
}

void	setup_and_run(const char *filename, t_flood_fill *fill)
{
	void			*mlx;
	void			*win;
	t_mini			d;
	t_draw_params	params;
	t_fp			param;

	params.tile_size = 40;
	params.window_width = fill->cols * params.tile_size;
	params.window_height = fill->rows * params.tile_size;
	mlx = mlx_init();
	win = mlx_new_window(mlx, params.window_width, params.window_height,
			"Map Window");
	d.init_ptr = mlx;
	params.d = &d;
	init_map(&d);
	fill->arg = filename;
	fill->map = convert_map(fill);
	params.mlx = mlx;
	params.win = win;
	param.dp = &params;
	param.f = fill;
	draw_tiles(fill, &params);
	mlx_key_hook(win, move_player, &param);
	mlx_hook(win, 17, 0, close_win, &param);
	mlx_loop(mlx);
}
