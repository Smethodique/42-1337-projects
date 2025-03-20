/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:57:24 by stakhtou          #+#    #+#             */
/*   Updated: 2025/01/25 20:29:38 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

int	cylinder(char **fields, struct s_config_data *data)
{
	char				**cords;
	struct s_cylinder	*cylinder;

	cylinder = malloc(sizeof(struct s_cylinder));
	if (!cylinder)
		return (set_error(&data->error_code, MALLOC_FAILURE), -1);
	cords = NULL;
	if (validate_fields(fields, &data->error_code, 6) == 0)
		return (free(cylinder), free_2d(cords), -1);
	cords = ft_split(fields[1], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free(cylinder), free_2d(cords), -1);
	parse_position(cylinder->position, cords, &data->error_code);
	cords = ft_split(fields[2], ",");
	if (validate_fields(cords, &data->error_code, 3) == 0)
		return (free(cylinder), free_2d(cords), -1);
	parse_vector(cylinder->vector, cords, &data->error_code);
	cylinder->diameter = ft_atof(fields[3], &data->error_code, 0, 1000);
	cylinder->height = ft_atof(fields[4], &data->error_code, 0, 1000);
	cords = ft_split(fields[5], ",");
	parse_color(cylinder->rgb, cords, &data->error_code);
	if (data->error_code != 0)
		return (free(cylinder), -1);
	data->bit_set |= CYLINDER;
	return (ft_lstadd_back(&data->cylinder_list, ft_lstnew(cylinder)), 1);
}

int	process_fields(char **fields, struct s_config_data *data)
{
	if (strcmp("A", fields[0]) == 0)
		return (ambiante_light(fields, data));
	else if (strcmp("C", fields[0]) == 0)
		return (camera(fields, data));
	else if (strcmp("L", fields[0]) == 0)
		return (light(fields, data));
	else if (strcmp("sp", fields[0]) == 0)
		return (sphere(fields, data));
	else if (strcmp("pl", fields[0]) == 0)
		return (plane(fields, data));
	else if (strncmp("cy", fields[0], 3) == 0)
		return (cylinder(fields, data));
	data->error_code = INVALID_ID;
	printf("INVALD IDENTIFIER: %s\n", fields[0]);
	return (-1);
}

int	conf_parse(char *file, struct s_config_data *data)
{
	int		fd;
	char	*line;
	char	**split;

	if (end_with(file, ".rt") != 1)
		return (set_error(&data->error_code, INVALID_FILE), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error(&data->error_code, FAILED_OPEN), -1);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, " \t\n");
		if (split != NULL && *line != '\n' && process_fields(split, data) == -1)
			return (free_2d(split), free(line), -1);
		free_2d(split);
		free(line);
		line = get_next_line(fd);
	}
	if ((data->bit_set & REQUIRED_FIELDS) != REQUIRED_FIELDS)
		return (set_error(&data->error_code, MISSING_ID), -1);
	return (1);
}

bool	validate_fields(char **fields, int8_t *err, int n)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i == n)
		return (1);
	if (i > n)
		*err = TOO_MANY_FIELDS;
	else
		*err = NOT_ENOUGH_FIELDS;
	return (0);
}
