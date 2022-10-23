/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:08:12 by bgannoun          #+#    #+#             */
/*   Updated: 2022/10/23 18:59:43 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr(long int n);
int	ft_putstr(char *str);
int	ft_printf(const char *placeholder, ...);

#endif