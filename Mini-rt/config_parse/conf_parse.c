/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:00:38 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 10:00:38 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"
#include <string.h>

int	ambiante_light(char **fields, struct s_config_data *data)
{
	char	**cords;

	cords = NULL;
	if ((data->bit_set & AMBIANT_LIGHT))
		return (set_error(&data->error_code, DUPLICATE), -1);
	if (validate_fields(fields, &data->error_code, 3) == 0)
		return (free_2d(cords), -1);
	data->ambiant_light.ratio = ft_atof(fields[1], &data->error_code, 0, 1);
	cords = ft_split(fields[2], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free_2d(cords), -1);
	parse_color(data->ambiant_light.rgb, cords, &data->error_code);
	if (data->error_code != 0)
		return (-1);
	data->bit_set |= AMBIANT_LIGHT;
	return (1);
}

int	camera(char **fields, struct s_config_data *data)
{
	char	**cords;

	cords = NULL;
	if ((data->bit_set & CAMERA))
		return (set_error(&data->error_code, DUPLICATE), -1);
	if (validate_fields(fields, &data->error_code, 4) == 0)
		return (free_2d(cords), -1);
	cords = ft_split(fields[1], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free_2d(cords), 1);
	parse_position(data->camera.position, cords, &data->error_code);
	cords = ft_split(fields[2], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free_2d(cords), -1);
	parse_vector(data->camera.vector, cords, &data->error_code);
	data->camera.fov = ft_atof(fields[3], &data->error_code, 0, 180);
	if (data->error_code != 0)
		return (-1);
	data->bit_set |= CAMERA;
	return (1);
}

int	sphere(char **fields, struct s_config_data *data)
{
	char			**cords;
	struct s_sphere	*sphere;

	sphere = malloc(sizeof(struct s_sphere));
	if (!sphere)
		return (set_error(&data->error_code, MALLOC_FAILURE), -1);
	cords = NULL;
	if (validate_fields(fields, &data->error_code, 4) == 0)
		return (free(sphere), -1);
	cords = ft_split(fields[1], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free(sphere), -1);
	parse_position(sphere->position, cords, &data->error_code);
	sphere->diameter = ft_atof(fields[2], &data->error_code, 0, 1000);
	cords = ft_split(fields[3], ",");
	parse_color(sphere->rgb, cords, &data->error_code);
	if (data->error_code != 0)
		return (free(sphere), -1);
	data->bit_set |= SPHERE;
	ft_lstadd_back(&data->sphere_list, ft_lstnew(sphere));
	return (1);
}

int	plane(char **fields, struct s_config_data *data)
{
	char			**cords;
	struct s_plane	*plane;

	plane = malloc(sizeof(struct s_plane));
	if (!plane)
		return (set_error(&data->error_code, MALLOC_FAILURE), -1);
	cords = NULL;
	if (validate_fields(fields, &data->error_code, 4) == 0)
		return (free(plane), -1);
	cords = ft_split(fields[1], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free(plane), -1);
	parse_position(plane->position, cords, &data->error_code);
	cords = ft_split(fields[2], ",");
	parse_vector(plane->vector, cords, &data->error_code);
	cords = ft_split(fields[3], ",");
	parse_color(plane->rgb, cords, &data->error_code);
	if (data->error_code != 0)
		return (free(plane), -1);
	ft_lstadd_back(&data->plane_list, ft_lstnew(plane));
	data->bit_set |= PLANE;
	return (1);
}

int	light(char **fields, struct s_config_data *data)
{
	char	**cords;

	cords = NULL;
	if (data->bit_set & LIGHT)
		return (set_error(&data->error_code, DUPLICATE), -1);
	if (validate_fields(fields, &data->error_code, 3) == 0)
		return (free_2d(cords), -1);
	cords = ft_split(fields[1], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free_2d(cords), -1);
	parse_position(data->light.position, cords, &data->error_code);
	data->light.brightness = ft_atof(fields[2], &data->error_code, 0, 1);
	if (data->error_code == PARSE_ERROR || data->error_code == OUT_OF_RANGE)
		return (-1);
	data->bit_set |= LIGHT;
	return (1);
}
