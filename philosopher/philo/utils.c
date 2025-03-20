/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:56:12 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

void	print_status(t_data *data, int id, char *status)
{
	pthread_mutex_lock(&data->death_mutex);
	if (!data->simulation_stop)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%lld %d %s\n", get_time() - data->start_time, id, status);
		pthread_mutex_unlock(&data->print_mutex);
	}
	pthread_mutex_unlock(&data->death_mutex);
}

int	check_one_philosopher(t_philosopher *philo)
{
	if (philo->data->num_philosophers == 1)
	{
		printf("%lld %d died\n", get_time() - philo->data->start_time,
			philo->id);
		return (1);
	}
	return (0);
}

int	is_simulation_stopped(t_data *data)
{
	int	simulation_stop;

	pthread_mutex_lock(&data->death_mutex);
	simulation_stop = data->simulation_stop;
	pthread_mutex_unlock(&data->death_mutex);
	return (simulation_stop);
}

void	smart_sleep(long long time, t_data *data)
{
	long long	start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
	{
		if (is_simulation_stopped(data))
			break ;
		usleep(100);
	}
}
