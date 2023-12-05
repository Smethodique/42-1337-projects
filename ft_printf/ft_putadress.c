/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:54:21 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/04 09:07:25 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(int add)
{
	int	len;

	ft_putstr("0x");
	ft_puthex(add);
	len = 2 + ft_puthex(add);
	return (len);
}
