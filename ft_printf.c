/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:57:13 by bgannoun          #+#    #+#             */
/*   Updated: 2022/10/23 18:59:06 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hex(long unsigned int n, char	*base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += hex(n / 16, base);
		count += hex(n % 16, base);
	}
	else
	{
		count += ft_putchar(base[n]);
	}
	return (count);
}

int	address(long long unsigned int n, char	*base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += hex(n / 16, base);
		count += hex(n % 16, base);
	}
	else
	{
		count += ft_putchar(base[n]);
	}
	return (count);
}

int	unsign(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putnbr(n);
	return (count);
}

int	percent(va_list args, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (hex(va_arg(args, long unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (hex(va_arg(args, long unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (unsign(va_arg(args, unsigned int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (address(va_arg(args, long long unsigned int),
				"0123456789abcdef") + 2);
	}
	return (0);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, placeholder);
	i = 0;
	count = 0;
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			i++;
			count += percent(list, placeholder[i]);
		}
		else
			count += ft_putchar(placeholder[i]);
		i++;
	}
	va_end(list);
	return (count);
}

// int main(void)
// {
// 	char a = 'z';
// 	char b = 'b';
// 	char c = 'i';
// 	int	n = 2;
// 	char *str = "hello";
// 	// ft_printf("%c%c%c\n%s", a, b, c, str);
// 	printf("|%d\n", printf("%%%p", str));
// 	printf("|%d\n", ft_printf("%%%p", str));
// 	// printf("%d", putstr(str));
// 	// printf("%%%d\n", n);
// 	// printf("%s %p\n", str, str);
// 	// printf("%ld", -4294967295);
// }