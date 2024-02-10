/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:02:46 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/08 08:43:24 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c, int *len);
int	ft_putstr(char *str);
int	ft_putuphex(size_t c);
int	ft_puthex(size_t c);
int	ft_putdec(long num);
int	ft_putundec(unsigned int num);
int	ft_calclen(int n);
int	ft_printf(const char *printer, ...);
int	ft_putadress(void *add);
#endif
