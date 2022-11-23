/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:35 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 14:40:19 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_sort_args(const char *str, va_list args, size_t i)
{
	int	x;
	char	*base;

	x = 0;
	base = "0123456789abcdef";
	if (str[i + 1] == 'c')
		return (ft_putchar_fd_count(va_arg(args, int), 1));
	else if (str[i + 1] == 's')
		return (ft_putstr_fd_count(va_arg(args, char *), 1));
	else if (str[i + 1] == 'p')
		return (ft_putnbr_base_hexa((unsigned long long)va_arg(args, void *), 1, base));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr_fd_count(va_arg(args, int), 1));
	else if (str[i + 1] == 'u')
		return (ft_putnbr_fd_usign(va_arg(args, unsigned int), 1));
	else if (str[i + 1] == 'x')
		return (ft_putnbr_base_hexa(va_arg(args, long long int), 0, base));
	else if (str[i + 1] == 'X')
		return (ft_putnbr_base_hexa(va_arg(args, long long int), 0, "0123456789ABCDEF"));
	else if (str[i + 1] == '%')
		return (ft_putchar_fd_count('%', 1));
	return (ft_putchar_fd_count(str[i + 1], 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int	x;

	va_start(args, str);
	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			x += ft_sort_args(str, args, i);
			i += 2;
		}
		else
		{
			x += ft_putchar_fd_count(str[i], 1);
			i++;
		}
	}
	return (x);
}

#include <stdio.h>

int main()
{
	int *p = NULL;
	p = malloc(sizeof(int) * 25);
	
	int x = ft_printf("%x-\n", 999999);
	int y = printf("%x-\n", 999999);
	// int x = ft_printf("---%d\n", 55555);
	// int y = printf("---%d\n", 55555);
	printf("\nx = %d\ny = %d\n", x, y);
	return 0;
}
