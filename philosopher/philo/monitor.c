/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:57:25 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	check_philosopher_death(t_philosopher *philo)
{
	long long	current_time;
	long long	last_meal_time;
	bool		is_dead;

	is_dead = false;
	pthread_mutex_lock(&philo->meal_mutex);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	current_time = get_time();
	if (current_time - last_meal_time >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (!philo->data->simulation_stop && !philo->is_dead)
		{
			pthread_mutex_lock(&philo->data->print_mutex);
			philo->data->simulation_stop = true;
			printf("%lld %d died\n", current_time - philo->data->start_time,
				philo->id);
			is_dead = true;
			pthread_mutex_unlock(&philo->data->print_mutex);
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
	}
	return (is_dead);
}

int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->num_philosophers);
	if (!threads)
		return (1);
	i = 0;
	data->start_time = get_time();
	while (i < data->num_philosophers)
	{
		if (pthread_create(&threads[i], NULL, philosopher_routine,
				&data->philosophers[i]))
			return (free(threads), 1);
		i++;
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	return (0);
}
