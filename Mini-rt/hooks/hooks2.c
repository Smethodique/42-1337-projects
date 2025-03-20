/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:19 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 20:52:15 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

static void	handle_camera_rotation(t_data *data, int keycode)
{
	if (keycode != HOME_KEY && keycode != END_KEY && keycode != DELETE
		&& keycode != PAGE_DOWN && keycode != PAGE_UP && keycode != INSERT)
		return ;
	if (keycode == HOME_KEY)
		data->config.camera.vector[Y] += 0.1;
	else if (keycode == END_KEY)
		data->config.camera.vector[Y] -= 0.1;
	else if (keycode == DELETE)
		data->config.camera.vector[X] -= 0.1;
	else if (keycode == PAGE_DOWN)
		data->config.camera.vector[X] += 0.1;
	else if (keycode == PAGE_UP)
		data->config.camera.vector[Z] -= 0.1;
	else if (keycode == INSERT)
		data->config.camera.vector[Z] += 0.1;
	scene_setup(data);
}

static void	handle_arrow_keys(t_data *data, int keycode)
{
	if (keycode == UP_ARROW)
	{
		if (data->selected_object.object_type == 's')
			((t_sphere *)data->selected_object.object)->diameter += 0.1;
		else if (data->selected_object.object_type == 'c')
			((t_cylinder *)data->selected_object.object)->diameter += 0.1;
		else if (data->selected_object.object_type == 'l')
			data->config.light.brightness += 0.1;
	}
	else if (keycode == DOWN_ARROW)
	{
		if (data->selected_object.object_type == 's')
			((t_sphere *)data->selected_object.object)->diameter += -0.1;
		else if (data->selected_object.object_type == 'c')
			((t_cylinder *)data->selected_object.object)->diameter += -0.1;
		else if (data->selected_object.object_type == 'l')
			data->config.light.brightness += -0.1;
	}
	else if (keycode == LEFT_ARROW && data->selected_object.object_type == 'c')
		((t_cylinder *)data->selected_object.object)->height += -0.1;
	else if (keycode == RIGHT_ARROW && data->selected_object.object_type == 'c')
		((t_cylinder *)data->selected_object.object)->height += 0.1;
}

void	handle_unique_keys(int keycode, t_data *data)
{
	if (data->selected_object.selected)
		handle_arrow_keys(data, keycode);
}

void	handle_rotate_keys(int keycode, t_data *data)
{
	if (data->selected_object.selected)
		handle_object_rotation(data, keycode);
	else
		handle_camera_rotation(data, keycode);
}
