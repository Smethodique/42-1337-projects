/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:01:11 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 22:38:20 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

void	vec3_add(t_vector3 result, const t_vector3 v1, const t_vector3 v2)
{
	result[0] = v1[0] + v2[0];
	result[1] = v1[1] + v2[1];
	result[2] = v1[2] + v2[2];
}

void	vec3_subtract(t_vector3 result, const t_vector3 v1, const t_vector3 v2)
{
	result[0] = v1[0] - v2[0];
	result[1] = v1[1] - v2[1];
	result[2] = v1[2] - v2[2];
}

void	vec3_multiply(t_vector3 result, const t_vector3 v, double t)
{
	result[0] = v[0] * t;
	result[1] = v[1] * t;
	result[2] = v[2] * t;
}

void	vec3_divide(t_vector3 result, const t_vector3 v, double t)
{
	if (fabs(t) > 1e-6f)
	{
		result[0] = v[0] / t;
		result[1] = v[1] / t;
		result[2] = v[2] / t;
	}
	else
	{
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}
}

double	vec3_dot(const t_vector3 v1, const t_vector3 v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}
