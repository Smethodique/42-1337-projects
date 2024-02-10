/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:13:39 by stakhtou          #+#    #+#             */
/*   Updated: 2024/02/10 18:51:15 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);

typedef struct g_GlobalData
{
	unsigned char	received_byte;
	int				received_bits;
}					t_GlobalData;

#endif