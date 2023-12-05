/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:27:55 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/05 17:37:48 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_spec(const char type, va_list args)
{
	int len;
	len = 0;
	
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
		len += ft_putadress(va_arg(args, int));
	return (len);
}

int ft_printf(const char *printer, ...)
{
    int i = 0;
    int len = 0;
    va_list args;
    va_start(args, printer);

    while (printer[i] != '\0')
    {
        if (printer[i] != '%')
        {
            ft_putchar(printer[i],&len);
            len++;
        }
        else
        {
            i++;
            len += ft_spec(printer[i], args);
        }
        i++;
    }

    va_end(args);
    return len;
}
// int main()
// {
// 	printf("%s",NULL);
// }