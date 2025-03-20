/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:23 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 20:34:04 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"
#include "includes/parse.h"
#include "includes/render.h"
#include <math.h>
#include <mlx.h>

void	print_error(int error_code)
{
	if (error_code == PARSE_ERROR)
		printf("Error: Parsing error\n");
	else if (error_code == TOO_MANY_FIELDS)
		printf("Error: Too many fields\n");
	else if (error_code == NOT_ENOUGH_FIELDS)
		printf("Error: Not enough fields\n");
	else if (error_code == INVALID_ID)
		printf("Error: Invalid ID\n");
	else if (error_code == INVALID_FILE)
		printf("Error: Invalid file\n");
	else if (error_code == OUT_OF_RANGE)
		printf("Error: Out of range\n");
	else if (error_code == FAILED_OPEN)
		printf("Error: Couldn't open the file\n");
	else if (error_code == MISSING_ID)
		printf("Error: Missing ID\n");
	else if (error_code == DUPLICATE)
		printf("Error: Duplicate ID\n");
}

void	initialize_data(t_data *data)
{
	data->mode = 'r';
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Failed to initialize mlx\n");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "miniRT");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		printf("Failed to create window\n");
		exit(EXIT_FAILURE);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		printf("Failed to create image\n");
		exit(EXIT_FAILURE);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->focal_length = 1;
}

void	cleanup_and_exit(t_data *data, int error_code)
{
	print_error(error_code);
	ft_lstclear(&data->config.sphere_list, free);
	ft_lstclear(&data->config.cylinder_list, free);
	ft_lstclear(&data->config.plane_list, free);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	static t_data	data;

	if (ac != 2)
		return (printf("Wrong number of arguments\n"), -1);
	if (conf_parse(av[1], &data.config) < 0)
		cleanup_and_exit(&data, data.config.error_code);
	initialize_data(&data);
	scene_setup(&data);
	render_scene(&data);
	set_up_hooks(data);
	mlx_loop(data.mlx);
	return (0);
}
