/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:13:39 by stakhtou          #+#    #+#             */
/*   Updated: 2024/02/10 19:17:54 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct g_GlobalData	g_lobal_data;

void	siguser1(int sig1)
{
	(void)sig1;
	g_lobal_data.received_byte <<= 1;
	g_lobal_data.received_bits++;
	if (g_lobal_data.received_bits == 8)
	{
		ft_printf("%c", g_lobal_data.received_byte);
		g_lobal_data.received_byte = 0;
		g_lobal_data.received_bits = 0;
	}
}

void	siguser2(int sig2)
{
	(void)sig2;
	g_lobal_data.received_byte <<= 1;
	g_lobal_data.received_byte |= 1;
	g_lobal_data.received_bits++;
	if (g_lobal_data.received_bits == 8)
	{
		ft_printf("%c", g_lobal_data.received_byte);
		g_lobal_data.received_byte = 0;
		g_lobal_data.received_bits = 0;
	}
}

int	main(void)
{
	if (signal(SIGUSR1, siguser1) == SIG_ERR)
	{
		ft_printf("Unable to register SIGUSR1 handler");
		exit(1);
	}
	if (signal(SIGUSR2, siguser2) == SIG_ERR)
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
