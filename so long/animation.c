/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:58:33 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/24 10:46:15 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	est_con(void **mlx)
{
	*mlx = mlx_init();
	if (!(*mlx))
		return ;
}

void	init_map(t_mini *d)
{
	int	width;
	int	height;

	width = 40;
	height = 40;
	d->black = mlx_xpm_file_to_image(d->init_ptr, "assets/black.xpm", &width,
			&height);
	d->wall = mlx_xpm_file_to_image(d->init_ptr, "assets/wall.xpm", &width,
			&height);
	d->coins = mlx_xpm_file_to_image(d->init_ptr, "assets/coin.xpm", &width,
			&height);
	d->door = mlx_xpm_file_to_image(d->init_ptr, "assets/exit.xpm", &width,
			&height);
	d->img_player = mlx_xpm_file_to_image(d->init_ptr, "assets/ball.xpm",
			&width, &height);
}

// void	draw_map(t_flood_fill *fill, t_draw_params *params)
// {


// 	if (!*(params->win))
// 		return ;
// 	draw_tiles(fill, params);
// }

int	key_press(int keycode, t_flood_fill *fill, t_draw_params *params)
{
	int	draw_x;
	int	draw_y;
	
	printf("ptr is %p fill->y %i fill->x%i\n", params->mlx, fill->y, fill->x);
	if (keycode == 13 && fill->map[fill->y - 1][fill->x] != '1')
		fill->y -= 1;
	else if (keycode == 0)
		fill->x -= 1;
	else if (keycode == 1)
		fill->y += 1;
	else if (keycode == 2)
		fill->x += 1;
	draw_x = fill->x * 40;
	draw_y = fill->y * 40;
	mlx_put_image_to_window(params->mlx, params->win, params->ball_img,
		draw_x, draw_y);
	return (0);
}

void	setup_and_run(const char *filename, t_flood_fill *fill)
{
	void			*mlx;
	void			*win;
	t_mini			d;
	t_draw_params	params;


	params.tile_size = 40;
	params.window_width = fill->cols * params.tile_size;
	params.window_height = fill->rows * params.tile_size;
	printf("Rows: %d, Cols: %d\n",params.window_width, params.window_height);
	mlx = mlx_init();
	win = mlx_new_window(mlx, params.window_width,params.window_height, "Map Window");
	if (!params.win)
		mlx_destroy_window(params.mlx, params.win);
	if (!mlx || !win)
		exit(1);
	d.init_ptr = mlx;
	init_map(params.d);
	fill->arg = filename;
	fill->map = convert_map(fill);
	params.mlx = mlx;
	params.win = win;
	printf("ptr is %p\n", params.mlx);

	//mlx_put_image_to_window(params.mlx, params.win, params.d->wall, 10, 10);
	//draw_map(fill, &params);
	draw_tiles(fill, &params);

	mlx_hook(win, 2, 1L << 0, key_press, &fill);
	mlx_loop(mlx);
}
