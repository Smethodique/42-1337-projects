/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:00:57 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/26 22:46:56 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "parse.h"
# define PI 3.14159265358979323846

typedef struct s_data	t_data;
struct					s_ray;
typedef struct s_ray	t_ray;
typedef double			t_vector3[3];
typedef double			t_point3[3];
typedef uint8_t			t_rgb[3];
typedef struct s_sphere	t_sphere;
typedef struct s_plane	t_plane;
typedef struct s_hit	t_hit;

typedef struct s_closest
{
	double				t;
	void				*object;
	char				type;
}						t_closest;
void					vec3_add(t_vector3 result, const t_vector3 v1,
							const t_vector3 v2);
void					vec3_subtract(t_vector3 result, const t_vector3 v1,
							const t_vector3 v2);
void					vec3_multiply(t_vector3 result, const t_vector3 v,
							double t);
void					vec3_divide(t_vector3 result, const t_vector3 v,
							double t);
double					vec3_dot(const t_vector3 v1, const t_vector3 v2);
void					vec3_cross(t_vector3 result, const t_vector3 v1,
							const t_vector3 v2);
void					vec3_normalize(t_vector3 result, const t_vector3 v);
double					vec3_length(t_vector3 vec);
void					vec3_copy(t_vector3 dest, const t_vector3 src);
void					ray_at(t_point3 result, const t_ray *ray, double t);
int						scene_setup(t_data *data);
int						init_mlx(t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
int						close_handler(t_data *data);
bool					intersect_sphere(t_ray *ray, t_sphere *sphere,
							t_hit *hit);
bool					intersect_plane(t_ray *ray, t_plane *plane, t_hit *hit);
t_ray					generate_ray_for_pixel(t_data *data, double x, double y,
							t_ray *ray);

#endif
