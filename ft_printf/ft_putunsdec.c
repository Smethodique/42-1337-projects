/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:27:55 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/04 01:01:07 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putundec(int num)
{
	int	len;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else if (num >= 0 && num <= 9)
	{
		ft_putchar(48 + num, len);
	}
	else if (num > 9)
	{
		ft_putundec(num / 10);
		ft_putundec(num % 10);
	}
	len = ft_calclen(num);
	return (len);
}
