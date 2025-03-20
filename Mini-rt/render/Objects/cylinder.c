/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:39:24 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/27 19:55:41 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

static bool	solve_quadratic(double a, double b, double c,
		t_quadratic_params *params)
{
	double	discriminant;
	double	temp;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	params->t1 = (-b - sqrtf(discriminant)) / (2 * a);
	params->t2 = (-b + sqrtf(discriminant)) / (2 * a);
	if (params->t1 > params->t2)
	{
		temp = params->t1;
		params->t1 = params->t2;
		params->t2 = temp;
	}
	return (true);
}

void	calculate_normal(t_vector3 p, t_vector3 normalized_dir, t_hit *hit)
{
	t_vector3	proj;
	t_vector3	center_to_hit;

	vec3_multiply(proj, normalized_dir, vec3_dot(p, normalized_dir));
	vec3_subtract(center_to_hit, p, proj);
	vec3_normalize(hit->normal, center_to_hit);
}

bool	intersect_cylinder_body(t_cylinder_intersectp *paramsp, t_hit *hit)
{
	t_vector3	intersection;
	t_vector3	p;

	calculate_intersection(paramsp->ray, paramsp->t.t1, intersection);
	if (!check_height(intersection, paramsp->cylinder, paramsp->normalized_dir))
	{
		calculate_intersection(paramsp->ray, paramsp->t.t2, intersection);
		if (!check_height(intersection, paramsp->cylinder,
				paramsp->normalized_dir))
			return (false);
	}
	hit->t = paramsp->t.t1;
	vec3_copy(hit->point, intersection);
	vec3_subtract(p, intersection, paramsp->cylinder->position);
	calculate_normal(p, paramsp->normalized_dir, hit);
	return (true);
}

bool	init_cylinder_intersection(t_ray *ray, struct s_cylinder *cylinder,
		t_intersect_cylinder_params *params)
{
	double	a;
	double	c;

	params->data = (t_cylinder_data){ray, cylinder, NULL, {0}};
	vec3_copy(params->data.normalized_dir, cylinder->vector);
	vec3_normalize(params->data.normalized_dir, params->data.normalized_dir);
	vec3_subtract(params->oc, ray->origin, cylinder->position);
	a = vec3_dot(ray->direction, ray->direction) - powf(vec3_dot(ray->direction,
				params->data.normalized_dir), 2);
	params->b = 2 * (vec3_dot(ray->direction, params->oc)
			- vec3_dot(ray->direction, params->data.normalized_dir)
			* vec3_dot(params->oc, params->data.normalized_dir));
	c = vec3_dot(params->oc, params->oc) - powf(vec3_dot(params->oc,
				params->data.normalized_dir), 2) - powf(cylinder->diameter / 2,
			2);
	return (solve_quadratic(a, params->b, c, &params->t));
}

bool	intersect_cylinder(t_ray *ray, struct s_cylinder *cylinder, t_hit *hit)
{
	t_intersect_cylinder_params	params;
	t_cylinder_intersectp		p;

	if (!init_cylinder_intersection(ray, cylinder, &params))
		return (false);
	if (params.t.t1 < 0)
	{
		if (params.t.t2 < 0)
			return (params.t.t1 = params.t.t2, false);
	}
	p = (t_cylinder_intersectp){ray, cylinder, params.t, {0}};
	vec3_copy(p.normalized_dir, params.data.normalized_dir);
	return (intersect_cylinder_body(&p, hit));
}
