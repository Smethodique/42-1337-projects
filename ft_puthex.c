/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:09:19 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/03 18:28:39 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuphex(int c, int len)
{
	int		j;
	char	buffer[2000];
	int		i;

	if (c == 0)
	{
		ft_putchar('0', 1);
		return ;
	}
	i = 0;
	while (c > 0)
	{
		j = c % 16;
		c = c / 16;
		if (j < 10)
			buffer[i++] = '0' + j;
		else if (j >= 10)
			buffer[i++] = 'a' + (j - 10);
	}
	while (i > 0)
	{
		len++;
		write(1, &buffer[--i], 1);
	}
}
