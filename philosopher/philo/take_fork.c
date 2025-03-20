/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:45:51 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	precise_sleep(long long duration)
{
	long long	start;
	long long	current;

	start = get_time();
	while (1)
	{
		current = get_time();
		if ((current - start) >= duration)
			break ;
		usleep(100);
	}
}

bool	attack_le(t_philosopher *philo, int first_fork, int second_fork)
{
	if (is_simulation_stopped(philo->data))
		return (false);
	pthread_mutex_lock(&philo->data->forks[first_fork].mutex);
	if (is_simulation_stopped(philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[first_fork].mutex);
		return (false);
	}
	print_status(philo->data, philo->id, "has taken a fork");
	if (philo->data->num_philosophers == 1)
	{
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_unlock(&philo->data->forks[first_fork].mutex);
		return (false);
	}
	pthread_mutex_lock(&philo->data->forks[second_fork].mutex);
	if (is_simulation_stopped(philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[first_fork].mutex);
		pthread_mutex_unlock(&philo->data->forks[second_fork].mutex);
		return (false);
	}
	print_status(philo->data, philo->id, "has taken a fork");
	return (true);
}

void	take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	if (!philo || !philo->data || is_simulation_stopped(philo->data))
		return ;
	left_fork = philo->id - 1;
	right_fork = (philo->id % philo->data->num_philosophers);
	if (philo->id % 2 == 0)
	{
		if (!attack_le(philo, right_fork, left_fork))
			return ;
	}
	else
	{
		if (!attack_le(philo, left_fork, right_fork))
			return ;
	}
}
