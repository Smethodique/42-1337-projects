/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:27:55 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/05 16:55:04 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_spec(const char type, va_list args, int len)
{
	if (type == 'c')
		len = ft_putchar(va_arg(args, int), &len);
	else if (type == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putdec(va_arg(args, int));
	else if (type == 'u')
		len += ft_putundec(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_puthex(va_arg(args, unsigned int));
	else if (type == 'X')
		len += ft_putuphex(va_arg(args, unsigned int));
	else if (type == 'p')
		len += ft_putadress(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *printer, ...)
{
    
    printer = 
}
