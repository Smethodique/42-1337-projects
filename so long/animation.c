/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:58:33 by stakhtou          #+#    #+#             */
/*   Updated: 2024/03/23 05:06:51 by stakhtou         ###   ########.fr       */
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

void	draw_map(t_flood_fill *fill, t_draw_params *params)
{
	int	window_width;
	int	window_height;

	window_width = fill->cols * params->tile_size;
	window_height = fill->rows * params->tile_size;
	if (*(params->win))
		mlx_destroy_window(params->mlx, *(params->win));
	*(params->win) = mlx_new_window(params->mlx, window_width, window_height,
			"Map Window");
	if (!*(params->win))
		return ;
	draw_tiles(fill, params);
}

void	setup_and_run(const char *map_filename)
{
	void			*mlx;
	void			*win;
	t_mini			d;
	t_flood_fill	fill;
	t_draw_params	params;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 0, 0, "Map Window");
	if (!mlx || !win)
		exit(1);
	d.init_ptr = mlx;
	init_map(&d);
	fill.arg = map_filename;
	fill.map = convert_map(&fill);
	params.mlx = mlx;
	params.win = &win;
	params.wall_img = d.wall;
	params.coin_img = d.coins;
	params.exit_img = d.door;
	params.black_img = d.black;
	params.ball_img = d.img_player;
	params.tile_size = 40;
	draw_map(&fill, &params);
	mlx_loop(mlx);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		printf("Usage: %s <map_filename>\n", av[0]);
// 		return (1);
// 	}
// 		system("leaks solong");
// 	setup_and_run(av[1]);
	
// 	while (1)
// 	{
// 	}
	
// 	return (0);
// }
