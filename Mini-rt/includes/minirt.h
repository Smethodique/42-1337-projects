/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:00:59 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/27 19:50:15 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "get_next_line.h"
# include "parse.h"
# include "render.h"
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <math.h>
# define REQUIRED_FIELDS 14
# define HEIGHT 1200
# define WIDTH 1600
# include "time.h"
# define X 0
# define Y 1
# define Z 2
# define R X
# define G Y
# define B Z
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define EIGHT_KEY 65431
# define TWO_KEY 65433
# define HOME_KEY 65360
# define END_KEY 65367
# define PAGE_UP 65365
# define PAGE_DOWN 65366
# define INSERT 65379
# define DELETE 65535
# define ESC 65307
# define F12 49
# define A 97
# define D 100
# define W 119
# define S 115

enum							e_ERROR_CODE
{
	DUPLICATE = -11,
	FAILED_OPEN = -10,
	INVALID_FILE = -9,
	INVALID_ID = -8,
	MISSING_ID = -7,
	PARSE_ERROR = -6,
	TOO_MANY_FIELDS = -5,
	NOT_ENOUGH_FIELDS = -4,
	OUT_OF_RANGE = -3,
	MALLOC_FAILURE = -2
};
enum							e_bit_set
{
	AMBIANT_LIGHT = 2,
	CAMERA = 4,
	LIGHT = 8,
	SPHERE = 16,
	PLANE = 32,
	CYLINDER = 64
};

typedef double					t_point3[3];
typedef u_int8_t				t_rgb[3];
typedef double					t_vector3[3];

typedef struct s_list
{
	void						*content;
	struct s_list				*next;
}								t_list;

struct							s_ambiant_lighting
{
	double						ratio;
	t_rgb						rgb;
};
typedef struct s_hit
{
	bool						hit;
	double						t;
	t_vector3					point;
	t_vector3					normal;
}								t_hit;
struct							s_cam
{
	t_point3					position;
	t_vector3					vector;
	u_int8_t					fov;
};
typedef struct s_light
{
	t_point3					position;
	double						brightness;
}								t_light;

typedef struct s_sphere
{
	t_point3					position;
	double						diameter;
	t_rgb						rgb;
}								t_sphere;

typedef struct s_plane
{
	t_point3					position;
	t_vector3					vector;
	t_rgb						rgb;
}								t_plane;

typedef struct s_cylinder
{
	t_point3					position;
	t_vector3					vector;
	double						diameter;
	double						height;
	t_rgb						rgb;
}								t_cylinder;

typedef struct s_config_data
{
	struct s_ambiant_lighting	ambiant_light;
	struct s_cam				camera;
	struct s_light				light;
	t_list						*plane_list;
	t_list						*sphere_list;
	t_list						*cylinder_list;
	u_int8_t					bit_set;
	int8_t						error_code;
}								t_config_data;
typedef struct s_ray
{
	t_point3					origin;
	t_vector3					direction;
}								t_ray;

typedef struct s_img
{
	void						*img;
	char						*addr;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
}								t_img;

typedef struct s_selected_object
{
	bool						selected;
	t_hit						hit;
	char						object_type;
	void						*object;
}								t_selected_object;

typedef struct s_data
{
	void						*mlx;
	void						*win;
	t_img						img;
	struct s_config_data		config;
	t_ray						camera_ray;
	double						viewport_height;
	double						viewport_width;
	double						focal_length;
	t_vector3					viewport_u;
	t_vector3					viewport_v;
	t_vector3					viewport_corner;
	t_point3					viewport_upper_left;
	t_vector3					pixel_delta_u;
	t_vector3					pixel_delta_v;
	t_vector3					camera_right;
	t_vector3					camera_up;
	t_selected_object			selected_object;
	char						mode;
}								t_data;

typedef struct s_render_vars
{
	t_ray						ray;
	t_rgb						color;
	int							x;
	int							y;
	int							samples;
	clock_t						start;
	double						r;
	double						pixel_x;
	double						pixel_y;
	bool						hit_anything;
	double						closest_t;
	t_hit						closest_hit;
	t_rgb						object_color;
	double						light_intensity;
	double						samples_squared;
	int							color_value;
	clock_t						end;
	double						time_spent;
	double						g;
	double						b;
}								t_render_vars;

typedef struct s_lighting_vars
{
	double						intensity;
	t_vector3					light_dir;
	t_vector3					offset_point;
	t_ray						shadow_ray;
	double						light_distance;
	double						diff;
	t_hit						shadow_hit;
	double						shadow_t;
	double						shadow_distance;
	double						shadow_factor;
}								t_lighting_vars;

typedef struct s_quadratic_params
{
	double						t1;
	double						t2;
	t_hit						*hit;
	t_vector3					normalized_dir;
}								t_quadratic_params;

typedef struct s_cylinder_data
{
	t_ray						*ray;
	struct s_cylinder			*cylinder;
	t_hit						*hit;
	t_vector3					normalized_dir;
}	t_cylinder_data;

typedef struct s_cylinder_intersect
{
	t_ray				*ray;
	struct s_cylinder	*cylinder;
	t_quadratic_params	t;
	t_vector3			normalized_dir;
}	t_cylinder_intersectp;
typedef struct s_intersect_cylinder_params
{
	t_vector3					oc;
	t_cylinder_data				data;
	t_quadratic_params			t;
	double						b;
}								t_intersect_cylinder_params;
typedef struct temp_struct
{
	t_hit						*closest;
	double						*closest_t;
}								t_temp_struct;
typedef struct s_quadratic_solution
{
	double						t0;
	double						t1;
}								t_quadratic_solution;

typedef struct s_sphere_intersect
{
	double					radius;
	double					radius2;
	t_vector3				oc;
	double					a;
	double					b;
	double					c;
	t_quadratic_solution	solution;
}	t_sphere_intersect;

typedef struct s_sphere_vars
{
	double						radius;
	double						radius2;
	t_vector3					oc;
	double						a;
	double						b;
	double						c;
	t_quadratic_solution		solution;
}	t_sphere_vars;

void							set_error(int8_t *error,
									enum e_ERROR_CODE code);
void							ft_lstclear(t_list **lst, void (*del)(void *));
void							ft_lstadd_back(t_list **lst, t_list *new);
t_list							*ft_lstnew(void *content);
int								scene_setup(t_data *data);
void							render_scene(t_data *data);
void							set_up_hooks(t_data data);
void							handle_camera_movement(t_data *data,
									int keycode);
void							handle_wasd_keys(int keycode, t_data *data);
void							handle_object_rotation(t_data *data,
									int keycode);
void							handle_rotate_keys(int keycode, t_data *data);
void							handle_unique_keys(int keycode, t_data *data);
void							handle_camera_movement(t_data *data,
									int keycode);
void							handle_object_movement(t_data *data,
									int keycode);
int								mouse_key(int keycode, int x, int y,
									t_data *data);
bool							intersect_cylinder(t_ray *ray,
									t_cylinder *cylinder, t_hit *hit);

t_ray							generate_ray_for_pixel(t_data *data, double x,
									double y, t_ray *ray);
bool							check_sphere_intersections(t_data *data,
									t_ray *ray, t_temp_struct *tmp,
									t_rgb object_color);
bool							check_cylinder_intersections(t_data *data,
									t_ray *ray, t_temp_struct *tmp,
									t_rgb object_color);
bool							check_plane_intersections(t_data *data,
									t_ray *ray, t_temp_struct *tmp,
									t_rgb object_color);
double							calculate_diffuse_lighting(t_data *data,
									t_vector3 point,
									t_vector3 normal);
double							calculate_shadow_factor(t_data *data,
									t_vector3 point, t_vector3 normal,
									double light_distance);
void							calculate_intersection(t_ray *ray, double t,
									t_vector3 intersection);
bool							solve_quadratics(double a, double b, double c,
									t_quadratic_solution *solution);
bool							init_cylinder_intersection(t_ray *ray,
									struct s_cylinder *cylinder,
									t_intersect_cylinder_params *params);
bool							check_height(t_vector3 intersection,
									struct s_cylinder *cylinder,
									t_vector3 normalized_dir);
void							ft_memcpy(void *dst, const void *src, size_t n);
#endif
