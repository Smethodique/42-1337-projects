/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:13:39 by stakhtou          #+#    #+#             */
/*   Updated: 2024/02/18 16:12:18 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct g_GlobalData	g_lobal_data;

void	siguser1(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	g_lobal_data.received_byte <<= 1;
	g_lobal_data.received_bits++;
	if (g_lobal_data.received_bits == 8)
	{
		if (g_lobal_data.received_byte == '\0')
		{
			kill(info->si_pid, SIGUSR1);
		}
		ft_printf("%c", g_lobal_data.received_byte);
		g_lobal_data.received_byte = 0;
		g_lobal_data.received_bits = 0;
	}
}

void	siguser2(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	g_lobal_data.received_byte <<= 1;
	g_lobal_data.received_byte |= 1;
	g_lobal_data.received_bits++;
	if (g_lobal_data.received_bits == 8)
	{
		if (g_lobal_data.received_byte == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", g_lobal_data.received_byte);
		g_lobal_data.received_byte = 0;
		g_lobal_data.received_bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_sigaction = siguser1;
	sa2.sa_sigaction = siguser2;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
	{
		ft_printf("Unable to register SIGUSR1 handler");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
	{
		ft_printf("Unable to register SIGUSR2 handler");
		exit(1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		sleep(1);
	}
	return (0);
}
