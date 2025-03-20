/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:15 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 20:48:02 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

static void	update_position(t_data *data, int axis, double value)
{
	if (data->selected_object.object_type == 's')
		((t_sphere *)data->selected_object.object)->position[axis] += value;
	else if (data->selected_object.object_type == 'c')
		((t_cylinder *)data->selected_object.object)->position[axis] += value;
	else if (data->selected_object.object_type == 'p')
		((t_plane *)data->selected_object.object)->position[axis] += value;
	else if (data->selected_object.object_type == 'l')
		data->config.light.position[axis] += value;
}

static void	update_orientation(t_data *data, int axis, double value)
{
	if (data->selected_object.object_type == 'c')
		((t_cylinder *)data->selected_object.object)->vector[axis] += value;
	else if (data->selected_object.object_type == 'p')
		((t_plane *)data->selected_object.object)->vector[axis] += value;
	else if (data->selected_object.object_type == 'l')
		data->config.light.position[axis] += value;
}

void	handle_object_movement(t_data *data, int keycode)
{
	if (keycode == W)
		update_position(data, 1, 0.1);
	else if (keycode == S)
		update_position(data, 1, -0.1);
	else if (keycode == A)
		update_position(data, 0, -0.1);
	else if (keycode == D)
		update_position(data, 0, 0.1);
	else if (keycode == EIGHT_KEY)
		update_position(data, Z, -0.1);
	else if (keycode == TWO_KEY)
		update_position(data, Z, 0.1);
}

void	handle_camera_movement(t_data *data, int keycode)
{
	if (keycode == W)
		data->config.camera.position[Y] -= 0.05;
	else if (keycode == S)
		data->config.camera.position[Y] += 0.5;
	else if (keycode == A)
		data->config.camera.position[X] += 0.5;
	else if (keycode == D)
		data->config.camera.position[X] -= 0.5;
	else if (keycode == EIGHT_KEY)
		data->config.camera.position[Z] += 0.5;
	else if (keycode == TWO_KEY)
		data->config.camera.position[Z] -= 0.5;
}

void	handle_object_rotation(t_data *data, int keycode)
{
	if (keycode == HOME_KEY)
		update_orientation(data, Y, 0.1);
	else if (keycode == END_KEY)
		update_orientation(data, Y, -0.1);
	else if (keycode == DELETE)
		update_orientation(data, X, -0.1);
	else if (keycode == PAGE_DOWN)
		update_orientation(data, X, 0.1);
	else if (keycode == PAGE_UP)
		update_orientation(data, Z, -0.1);
	else if (keycode == INSERT)
		update_orientation(data, Z, 0.1);
}
