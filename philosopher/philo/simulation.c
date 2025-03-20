/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 05:59:07 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	check_any_philosopher_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (check_philosopher_death(&data->philosophers[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	eat(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	if (is_simulation_stopped(data))
		return (false);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(data, philo->id, "is eating");
	usleep(data->time_to_eat * 1000);
	check_any_philosopher_death(data);
	pthread_mutex_unlock(&data->forks[philo->id - 1].mutex);
	pthread_mutex_unlock(&data->forks[philo->id
		% data->num_philosophers].mutex);
	return (true);
}

static bool	handle_dining(t_philosopher *philo, t_data *data)
{
	print_status(data, philo->id, "is thinking");
	if (data->num_philosophers % 2 != 0)
		usleep(500);
	if (philo->id % 2 == 0)
		usleep(500);
	if (data->num_philosophers > 1)
	{
		take_forks(philo);
		if (!eat(philo))
			return (false);
		if (is_simulation_stopped(data))
			return (false);
		print_status(data, philo->id, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	else
	{
		take_forks(philo);
		print_status(data, philo->id, "died");
		return (false);
	}
	return (true);
}

static void	philosopher_loop(t_philosopher *philo, t_data *data,
		bool *has_eaten_enough)
{
	while (!is_simulation_stopped(data) && !*has_eaten_enough)
	{
		if (!handle_dining(philo, data))
			break ;
		pthread_mutex_lock(&philo->meal_mutex);
		if (data->meals_required != -1
			&& philo->meals_eaten >= data->meals_required)
		{
			*has_eaten_enough = true;
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		if (check_any_philosopher_death(data))
			break ;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	t_data			*data;
	bool			has_eaten_enough;

	philo = (t_philosopher *)arg;
	data = philo->data;
	has_eaten_enough = false;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	philosopher_loop(philo, data, &has_eaten_enough);
	return (NULL);
}
