/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakhtou <stakhtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:02:46 by stakhtou          #+#    #+#             */
/*   Updated: 2023/12/05 16:47:20 by stakhtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c, int *len);
int	ft_putstr(char *str);
int	ft_putuphex(int c);
int	ft_puthex(int c);
int	ft_putdec(int num);
int	ft_putundec(int num);
int	calclen(int n);
int	ft_printf(const char *printer, ...);
#endif
