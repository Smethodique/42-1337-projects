/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:50:55 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/27 16:06:23 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

bool	solve_quadratic(double a, double b, double c,
		t_quadratic_solution *solution)
{
	double	discriminant;
	double	sqrt_disc;
	double	inv_2a;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
	{
		return (false);
	}
	sqrt_disc = sqrt(discriminant);
	inv_2a = 0.5 / a;
	solution->t0 = (-b - sqrt_disc) * inv_2a;
	solution->t1 = (-b + sqrt_disc) * inv_2a;
	return (true);
}

bool	intersect_sphere(t_ray *ray, t_sphere *sphere, t_hit *hit)
{
	t_sphere_vars	vars;

	vars.radius = sphere->diameter * 0.5;
	vars.radius2 = vars.radius * vars.radius;
	vec3_subtract(vars.oc, ray->origin, sphere->position);
	vars.a = vec3_dot(ray->direction, ray->direction);
	vars.b = 2.0 * vec3_dot(ray->direction, vars.oc);
	vars.c = vec3_dot(vars.oc, vars.oc) - vars.radius2;
	if (!solve_quadratic(vars.a, vars.b, vars.c, &vars.solution))
		return (hit->hit = false, false);
	if (vars.solution.t0 < 0)
	{
		vars.solution.t0 = vars.solution.t1;
		if (vars.solution.t0 < 0)
			return (hit->hit = false, false);
	}
	hit->t = vars.solution.t0;
	hit->hit = true;
	vec3_multiply(hit->point, ray->direction, vars.solution.t0);
	vec3_add(hit->point, ray->origin, hit->point);
	vec3_subtract(hit->normal, hit->point, sphere->position);
	vec3_normalize(hit->normal, hit->normal);
	return (true);
}

void	calculate_intersection(t_ray *ray, double t, t_vector3 intersection)
{
	vec3_multiply(intersection, ray->direction, t);
	vec3_add(intersection, ray->origin, intersection);
}
