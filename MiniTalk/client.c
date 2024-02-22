/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:13:39 by stakhtou          #+#    #+#             */
/*   Updated: 2024/02/18 20:25:13 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(50);
		i--;
	}
}

void	sig_handler(int siga)
{
	if (siga == SIGUSR1 || siga == SIGUSR2)
	{
		ft_printf("Received\n");
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if(pid == -1)
		{
			exite(1);
		}
		message = av[2];
		while (*message)
		{
			send_bit(*message, pid);
			message++;
		}
		send_bit('\n', pid);
		send_bit('\0', pid);
		return (0);
	}
	else
	{
		return (1);
	}
}
