/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:13 by stakhtou          #+#    #+#             */
/*   Updated: 2025/02/06 13:38:10 by baarif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>
#include <minirt.h>

double	calculate_lighting(t_data *data, t_vector3 point, t_vector3 normal)
{
	double	intensity;
	double	light_distance;

	intensity = calculate_diffuse_lighting(data, point, normal);
	light_distance = vec3_length(data->config.light.position);
	intensity *= calculate_shadow_factor(data, point, normal, light_distance);
	return (fmin(intensity, 1.0));
}

void	initialize_render_vars(t_render_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->samples = 1;
	vars->object_color[0] = 0;
	vars->object_color[1] = 0;
	vars->object_color[2] = 0;
}

void	render_sample(t_data *data, t_render_vars *vars, int sx, int sy)
{
	(void)sy;
	vars->pixel_x = vars->x + (double)sx / (double)vars->samples;
	vars->pixel_y = vars->y + (double)sx / (double)vars->samples;
	generate_ray_for_pixel(data, vars->pixel_x, vars->pixel_y, &vars->ray);
	vars->hit_anything = false;
	vars->closest_t = INFINITY;
	vars->hit_anything |= check_sphere_intersections(data, &vars->ray,
			&(t_temp_struct){&vars->closest_hit, &vars->closest_t},
			vars->object_color);
	vars->hit_anything |= check_cylinder_intersections(data, &vars->ray,
			&(t_temp_struct){&vars->closest_hit, &vars->closest_t},
			vars->object_color);
	vars->hit_anything |= check_plane_intersections(data, &vars->ray,
			&(t_temp_struct){&vars->closest_hit, &vars->closest_t},
			vars->object_color);
	if (vars->hit_anything)
	{
		vars->light_intensity = calculate_lighting(data,
				vars->closest_hit.point,
				vars->closest_hit.normal);
		vars->r += vars->object_color[0] * vars->light_intensity;
		vars->g += vars->object_color[1] * vars->light_intensity;
		vars->b += vars->object_color[2] * vars->light_intensity;
	}
}

void	render_pixel(t_data *data, t_render_vars *vars)
{
	int	sy;
	int	sx;

	vars->r = 0;
	vars->g = 0;
	vars->b = 0;
	sy = 0;
	while (sy < vars->samples)
	{
		sx = 0;
		while (sx < vars->samples)
		{
			render_sample(data, vars, sx, sy);
			sx++;
		}
		sy++;
	}
	vars->samples_squared = vars->samples * vars->samples;
	vars->color[0] = (int)(vars->r / vars->samples_squared);
	vars->color[1] = (int)(vars->g / vars->samples_squared);
	vars->color[2] = (int)
		(vars->b / vars->samples_squared);
	vars->color_value = (vars->color[0] << 16)
		| (vars->color[1] << 8) | vars->color[2];
	my_mlx_pixel_put(data, vars->x, vars->y, vars->color_value);
}

void	render_scene(t_data *data)
{
	t_render_vars	vars;

	initialize_render_vars(&vars);
	vars.start = clock();
	while (vars.y < HEIGHT)
	{
		vars.x = 0;
		while (vars.x < WIDTH)
		{
			if (data->mode == 's')
				if ((vars.x % 4 == 0) && (vars.y % 4 == 0))
					render_pixel(data, &vars);
			if (data->mode == 'r')
				render_pixel(data, &vars);
			vars.x++;
		}
		vars.y++;
	}
	vars.end = clock();
	vars.time_spent = (double)(vars.end - vars.start) / CLOCKS_PER_SEC;
	printf("Rendering time: %.2f seconds\n", vars.time_spent);
}
