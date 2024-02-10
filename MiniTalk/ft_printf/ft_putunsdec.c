/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:27:55 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/08 08:43:06 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putundec(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		ft_putchar('0', &len);
		return (len);
	}
	else if (num == 4294967295)
		return (ft_putstr("4294967295"));
	else
	{
		if (num <= 9)
		{
			ft_putchar('0' + num, &len);
			return (len);
		}
		else
		{
			len += ft_putundec(num / 10);
			len += ft_putundec(num % 10);
			return (len);
		}
	}
}
