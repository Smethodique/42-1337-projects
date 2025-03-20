/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:13 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/27 16:53:38 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>
#include <minirt.h>

t_ray	generate_ray_for_pixel(t_data *data, double x, double y, t_ray *ray)
{
	double		u;
	double		v;
	t_vector3	pixel_pos;
	t_vector3	scaled_u;
	t_vector3	scaled_v;

	ray->direction[0] = 0;
	ray->direction[1] = 0;
	ray->direction[2] = 0;
	u = (double)x / (double)(WIDTH - 1);
	v = (double)y / (double)(HEIGHT - 1);
	vec3_copy(pixel_pos, (t_vector3){0});
	vec3_copy(scaled_u, (t_vector3){0});
	vec3_copy(scaled_v, (t_vector3){0});
	vec3_multiply(scaled_u, data->viewport_u, u);
	vec3_multiply(scaled_v, data->viewport_v, v);
	vec3_copy(pixel_pos, data->viewport_corner);
	vec3_add(pixel_pos, pixel_pos, scaled_u);
	vec3_add(pixel_pos, pixel_pos, scaled_v);
	vec3_copy(ray->origin, data->config.camera.position);
	vec3_subtract(ray->direction, pixel_pos, ray->origin);
	vec3_normalize(ray->direction, ray->direction);
	return (*ray);
}

bool	check_sphere_intersections(t_data *data, t_ray *ray, t_temp_struct *tmp,
		t_rgb object_color)
{
	bool		hit_anything;
	t_hit		hit;
	t_list		*sphere_list;
	t_sphere	*sphere;

	hit_anything = false;
	sphere_list = data->config.sphere_list;
	while (sphere_list)
	{
		sphere = (t_sphere *)sphere_list->content;
		if (intersect_sphere(ray, sphere, &hit) && hit.t < *tmp->closest_t)
		{
			*tmp->closest_t = hit.t;
			*tmp->closest = hit;
			hit_anything = true;
			ft_memcpy(object_color, sphere->rgb, sizeof(t_rgb));
		}
		sphere_list = sphere_list->next;
	}
	return (hit_anything);
}

bool	check_cylinder_intersections(t_data *data, t_ray *ray,
		t_temp_struct *tmp, t_rgb object_color)
{
	bool		hit_anything;
	t_hit		hit;
	t_list		*cylinder_list;
	t_cylinder	*cylinder;

	hit_anything = false;
	cylinder_list = data->config.cylinder_list;
	while (cylinder_list)
	{
		cylinder = (t_cylinder *)cylinder_list->content;
		if (intersect_cylinder(ray, cylinder, &hit) && hit.t < *tmp->closest_t)
		{
			*tmp->closest_t = hit.t;
			*tmp->closest = hit;
			hit_anything = true;
			memcpy(object_color, cylinder->rgb, sizeof(t_rgb));
		}
		cylinder_list = cylinder_list->next;
	}
	return (hit_anything);
}

bool	check_plane_intersections(t_data *data, t_ray *ray, t_temp_struct *tmp,
		t_rgb object_color)
{
	bool	hit_anything;
	t_hit	hit;
	t_list	*plane_list;
	t_plane	*plane;

	hit_anything = false;
	plane_list = data->config.plane_list;
	while (plane_list)
	{
		plane = (t_plane *)plane_list->content;
		if (intersect_plane(ray, plane, &hit) && hit.t < *tmp->closest_t)
		{
			*tmp->closest_t = hit.t;
			*tmp->closest = hit;
			hit_anything = true;
			memcpy(object_color, plane->rgb, sizeof(t_rgb));
		}
		plane_list = plane_list->next;
	}
	return (hit_anything);
}

double	calculate_diffuse_lighting(t_data *data, t_vector3 point,
		t_vector3 normal)
{
	t_lighting_vars	vars;

	vars.intensity = data->config.ambiant_light.ratio;
	vec3_multiply(vars.offset_point, normal, 0.001f);
	vec3_add(vars.offset_point, point, vars.offset_point);
	vec3_subtract(vars.light_dir, data->config.light.position,
		vars.offset_point);
	vars.light_distance = vec3_length(vars.light_dir);
	vec3_normalize(vars.light_dir, vars.light_dir);
	vars.diff = vec3_dot(normal, vars.light_dir);
	if (vars.diff > 0)
		vars.intensity += vars.diff * data->config.light.brightness;
	return (vars.intensity);
}
