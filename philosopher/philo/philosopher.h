/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:45 by stakhtou          #+#    #+#             */
/*   Updated: 2024/10/27 03:56:43 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	int				id;
	bool			is_taken;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	bool			is_eating;
	bool			is_dead;
	long long		last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	struct s_data	*data;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
}					t_philosopher;

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	int				simulation_stop;
	long long		start_time;
	t_fork			*forks;
	t_philosopher	*philosophers;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
}					t_data;

void				ft_putstr_fd(char *s, int fd);
bool				is_valid_number(char *str);
bool				ft_atoi(char *str, int *result);
bool				validate_arguments(int argc, char **argv);
bool				validate_input(t_data *data);
bool				init_data(t_data *data, int argc, char **argv);
bool				init_philosophers(t_data *data);
bool				init_forks(t_data *data);
void				cleanup_simulation(t_data *data);
int					start_simulation(t_data *data);
void				smart_sleep(long long time, t_data *data);
int					get_time(void);
int					is_simulation_stopped(t_data *data);
void				print_status(t_data *data, int id, char *status);
void				take_forks(t_philosopher *philo);
bool				check_philosopher_death(t_philosopher *philo);
bool				eat(t_philosopher *philo);
void				*philosopher_routine(void *arg);
void				precise_sleep(long long duration);
bool				attack_le(t_philosopher *philo, int first_fork,
						int second_fork);
int					check_one_philosopher(t_philosopher *philo);

#endif