/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:57:25 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[0] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_atoi(char *str, int *result)
{
	long	num;
	int		i;

	if (!str || !result)
		return (false);
	num = 0;
	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (ft_putstr_fd("invalid format\n", 2), false);
		i++;
	}
	*result = (int)num;
	return (true);
}

bool	validate_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (false);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: Invalid argument format\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	validate_input(t_data *data)
{
	if (!data)
		return (false);
	if (data->num_philosophers <= 0 || data->num_philosophers > 200)
	{
		ft_putstr_fd("Error: Invalid number of philosophers (1-200)\n", 2);
		return (false);
	}
	if (data->time_to_die <= 0)
	{
		ft_putstr_fd("Error: Invalid time to die\n", 2);
		return (false);
	}
	if (data->time_to_eat <= 0)
	{
		ft_putstr_fd("Error: Invalid time to eat\n", 2);
		return (false);
	}
	if (data->time_to_sleep <= 0)
	{
		ft_putstr_fd("Error: Invalid time to sleep\n", 2);
		return (false);
	}
	if (data->meals_required <= 0 && data->meals_required != -1)
		return (ft_putstr_fd("Error: Invalid number of meals\n", 2), false);
	return (true);
}
