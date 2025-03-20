/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:17 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 20:47:43 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>

int	close_window(t_data *data)
{
	if (data->img.img && data->mlx)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_lstclear(&data->config.sphere_list, free);
	ft_lstclear(&data->config.cylinder_list, free);
	ft_lstclear(&data->config.plane_list, free);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	if (keycode == 108)
	{
		data->selected_object.object_type = 'l';
		data->selected_object.selected = 1;
	}
	if (keycode == 96)
	{
		if (data->mode == 's')
			data->mode = 'r';
		else if (data->mode == 'r')
			data->mode = 's';
	}
	if (keycode == 32)
		if (data->selected_object.selected)
			data->selected_object.selected = 0;
	handle_wasd_keys(keycode, data);
	handle_rotate_keys(keycode, data);
	handle_unique_keys(keycode, data);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	render_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (1);
}

void	handle_wasd_keys(int keycode, t_data *data)
{
	if (data->selected_object.selected)
		handle_object_movement(data, keycode);
	else
		handle_camera_movement(data, keycode);
}

void	set_up_hooks(t_data data)
{
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
}
