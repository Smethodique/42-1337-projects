/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:39:24 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 22:40:02 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

void	vec3_cross(t_vector3 result, const t_vector3 v1, const t_vector3 v2)
{
	result[0] = v1[1] * v2[2] - v1[2] * v2[1];
	result[1] = v1[2] * v2[0] - v1[0] * v2[2];
	result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void	vec3_normalize(t_vector3 result, const t_vector3 v)
{
	double	length;

	length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	if (length > 0.0000001f)
		vec3_divide(result, v, length);
	else
	{
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}
}

void	vec3_copy(t_vector3 dest, const t_vector3 src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

void	ray_at(t_point3 result, const t_ray *ray, double t)
{
	t_vector3	scaled_dir;

	vec3_multiply(scaled_dir, ray->direction, t);
	vec3_add(result, ray->origin, scaled_dir);
}

double	vec3_length(t_vector3 vec)
{
	return (sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}
