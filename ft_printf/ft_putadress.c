/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:54:21 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/07 11:52:50 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(void *add)
{
	int	len;

	ft_putstr("0x");
	len = 2 + ft_puthex((size_t)add);
	return (len);
}
