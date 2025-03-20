/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:28:24 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 22:33:59 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include <math.h>

void	ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
}

static void	check_cylinder_intersections_local(t_ray *ray, t_data *data,
		t_hit *closest_hit, t_closest *closest)
{
	t_list	*current;
	t_hit	hit;

	current = data->config.cylinder_list;
	while (current)
	{
		if (intersect_cylinder(ray, current->content, &hit)
			&& hit.t < closest->t)
		{
			closest->t = hit.t;
			*closest_hit = hit;
			closest->object = current->content;
			closest->type = 'c';
		}
		current = current->next;
	}
}

static void	check_sphere_intersections_local(t_ray *ray, t_data *data,
		t_hit *closest_hit, t_closest *closest)
{
	t_list	*current;
	t_hit	hit;

	current = data->config.sphere_list;
	while (current)
	{
		if (intersect_sphere(ray, current->content, &hit) && hit.t < closest->t)
		{
			closest->t = hit.t;
			*closest_hit = hit;
			closest->object = current->content;
			closest->type = 's';
		}
		current = current->next;
	}
}

static void	check_plane_intersections_local(t_ray *ray, t_data *data,
		t_hit *closest_hit, t_closest *closest)
{
	t_list	*current;
	t_hit	hit;

	current = data->config.plane_list;
	while (current)
	{
		if (intersect_plane(ray, current->content, &hit) && hit.t < closest->t)
		{
			closest->t = hit.t;
			*closest_hit = hit;
			closest->object = current->content;
			closest->type = 'p';
		}
		current = current->next;
	}
}

int	mouse_key(int keycode, int x, int y, t_data *data)
{
	t_ray			ray;
	static t_hit	closest_hit;
	t_closest		closest;

	closest_hit = (t_hit){0};
	(void)keycode;
	closest.t = INFINITY;
	closest.object = 0;
	closest.type = 0;
	ray = generate_ray_for_pixel(data, x, y, &ray);
	check_cylinder_intersections_local(&ray, data, &closest_hit, &closest);
	check_sphere_intersections_local(&ray, data, &closest_hit, &closest);
	check_plane_intersections_local(&ray, data, &closest_hit, &closest);
	if (closest.object)
		data->selected_object = (t_selected_object){1, closest_hit,
			closest.type, closest.object};
	return (1);
}
