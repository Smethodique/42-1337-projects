/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:09:19 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/05 16:28:17 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(int c)
{
	int		j;
	char	buffer[2000];
	int		i;
	int		len;

	len = 0;
	if (c == 0)
		ft_putchar('0', 1);
	i = 0;
	while (c > 0)
	{
		j = c % 16;
		c = c / 16;
		if (j < 10)
			buffer[i++] = '0' + j;
		else if (j >= 10)
			buffer[i++] = 'A' + (j - 10);
	}
	while (i > 0)
	{
		len++;
		write(1, &buffer[--i], 1);
	}
	return (len);
}
