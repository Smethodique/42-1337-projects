/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/26 22:43:54 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_data(t_data *data, int argc, char **argv)
{
	if (!data || !argv)
		return (false);
	if (!validate_arguments(argc, argv))
		return (false);
	if (!ft_atoi(argv[1], &data->num_philosophers) || !ft_atoi(argv[2],
			&data->time_to_die) || !ft_atoi(argv[3], &data->time_to_eat)
		|| !ft_atoi(argv[4], &data->time_to_sleep))
		return (false);
	data->meals_required = -1;
	if (argc == 6 && !ft_atoi(argv[5], &data->meals_required))
		return (false);
	data->simulation_stop = false;
	data->philosophers = NULL;
	data->forks = NULL;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (false);
	return (validate_input(data));
}

bool	init_philosophers(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (!data->philosophers)
		return (false);
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].is_eating = false;
		data->philosophers[i].is_dead = false;
		data->philosophers[i].last_meal_time = 0;
		data->philosophers[i].data = data;
		if (pthread_mutex_init(&data->philosophers[i].meal_mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->philosophers[i].meal_mutex);
			return (free(data->philosophers), false);
		}
		i++;
	}
	return (true);
}

bool	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * data->num_philosophers);
	if (!data->forks)
		return (false);
	i = 0;
	while (i < data->num_philosophers)
	{
		data->forks[i].is_taken = false;
		if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i].mutex);
			free(data->forks);
			return (false);
		}
		i++;
	}
	return (true);
}
