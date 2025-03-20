/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:51:51 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	cleanup_simulation(t_data *data)
{
	int	i;

	if (data->philosophers)
	{
		free(data->philosophers);
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->num_philosophers)
			pthread_mutex_destroy(&data->forks[i++].mutex);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!init_data(&data, argc, argv))
		return (1);
	if (!init_philosophers(&data))
	{
		cleanup_simulation(&data);
		return (1);
	}
	if (!init_forks(&data))
	{
		cleanup_simulation(&data);
		return (1);
	}
	start_simulation(&data);
	cleanup_simulation(&data);
	return (0);
}
