/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:09 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 23:02:48 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "render.h"

static void	setup_camera(t_data *data, t_vector3 *u, t_vector3 *v, t_vector3 *w)
{
	t_vector3	up;
	t_vector3	view_direction;

	up[0] = 0;
	up[1] = -1;
	up[2] = 0;
	vec3_subtract(view_direction, data->config.camera.vector,
		data->config.camera.position);
	vec3_normalize(*w, view_direction);
	vec3_cross(*u, up, *w);
	vec3_normalize(*u, *u);
	vec3_cross(*v, *w, *u);
}

static void	setup_dimensions(t_data *data, t_vector3 viewport_u,
		t_vector3 viewport_v, t_vector3 *w)
{
	t_vector3	u;
	t_vector3	v;
	double		fov_rad;

	setup_camera(data, &u, &v, w);
	fov_rad = data->config.camera.fov * PI / 180.0;
	data->viewport_height = 2.0 * tan(fov_rad / 2);
	data->viewport_width = data->viewport_height * ((double)WIDTH / HEIGHT);
	vec3_multiply(viewport_u, u, data->viewport_width);
	vec3_multiply(viewport_v, v, data->viewport_height);
	vec3_copy(data->viewport_u, viewport_u);
	vec3_copy(data->viewport_v, viewport_v);
	vec3_divide(data->pixel_delta_u, viewport_u, WIDTH);
	vec3_divide(data->pixel_delta_v, viewport_v, HEIGHT);
}

static void	setup_corner(t_data *data, t_vector3 viewport_u,
		t_vector3 viewport_v, t_vector3 w)
{
	t_vector3	focal_vec;
	t_vector3	viewport_center;
	t_vector3	half_u;
	t_vector3	half_v;

	vec3_multiply(focal_vec, w, data->focal_length);
	vec3_add(viewport_center, data->config.camera.position, focal_vec);
	vec3_divide(half_u, viewport_u, 2);
	vec3_divide(half_v, viewport_v, 2);
	vec3_copy(data->viewport_corner, viewport_center);
	vec3_subtract(data->viewport_corner, data->viewport_corner, half_u);
	vec3_subtract(data->viewport_corner, data->viewport_corner, half_v);
}

int	scene_setup(t_data *data)
{
	t_vector3	viewport_u;
	t_vector3	viewport_v;
	t_vector3	w;

	setup_dimensions(data, viewport_u, viewport_v, &w);
	setup_corner(data, viewport_u, viewport_v, w);
	return (1);
}

double	calculate_shadow_factor(t_data *data, t_vector3 point, t_vector3 normal,
		double light_distance)
{
	t_lighting_vars	vars;
	bool			shadow_hit;

	vec3_multiply(vars.offset_point, normal, 0.001f);
	vec3_add(vars.offset_point, point, vars.offset_point);
	vec3_subtract(vars.light_dir, data->config.light.position,
		vars.offset_point);
	vec3_normalize(vars.light_dir, vars.light_dir);
	vec3_copy(vars.shadow_ray.origin, vars.offset_point);
	vec3_copy(vars.shadow_ray.direction, vars.light_dir);
	vars.shadow_t = INFINITY;
	shadow_hit = check_sphere_intersections(data, &vars.shadow_ray,
			&(t_temp_struct){&vars.shadow_hit, &vars.shadow_t}, (t_rgb){0})
		|| check_cylinder_intersections(data, &vars.shadow_ray,
			&(t_temp_struct){&vars.shadow_hit, &vars.shadow_t}, (t_rgb){0})
		|| check_plane_intersections(data, &vars.shadow_ray,
			&(t_temp_struct){&vars.shadow_hit, &vars.shadow_t}, (t_rgb){0});
	if (shadow_hit && vars.shadow_hit.t < light_distance)
		return (0.75);
	return (1.0);
}
