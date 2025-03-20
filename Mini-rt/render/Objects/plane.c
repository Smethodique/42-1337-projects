/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:03 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/27 16:23:25 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

bool	intersect_plane(t_ray *ray, t_plane *plane, t_hit *hit)
{
	double		denom;
	t_vector3	normalized_normal;
	t_vector3	p0l0;
	double		t;

	vec3_copy(normalized_normal, plane->vector);
	vec3_normalize(normalized_normal, normalized_normal);
	denom = vec3_dot(normalized_normal, ray->direction);
	if (fabs(denom) < 1e-6)
		return (hit->hit = false, false);
	vec3_subtract(p0l0, plane->position, ray->origin);
	t = vec3_dot(p0l0, normalized_normal) / denom;
	if (t < 0)
		return (hit->hit = false, false);
	hit->t = t;
	hit->hit = true;
	vec3_multiply(hit->point, ray->direction, t);
	vec3_add(hit->point, ray->origin, hit->point);
	if (denom > 0)
		vec3_multiply(hit->normal, normalized_normal, -1);
	else
		vec3_copy(hit->normal, normalized_normal);
	return (true);
}

bool	check_height(t_vector3 intersection, struct s_cylinder *cylinder,
		t_vector3 normalized_dir)
{
	t_vector3	p;
	double		height;

	vec3_subtract(p, intersection, cylinder->position);
	height = vec3_dot(p, normalized_dir);
	if (height < 0 || height > cylinder->height)
		return (false);
	return (true);
}
