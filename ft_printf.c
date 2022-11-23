/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:35 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 11:34:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

static int	ft_sort_args(const char *str, va_list args, size_t i)
{
	char	*base;

	base = "0123456789abcdef";
	if (str[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (str[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[i + 1] == 'p')
		ft_putnbr_base_hexa((unsigned long long)va_arg(args, void *), 1, base);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (str[i + 1] == 'u')
		ft_putnbr_fd_usign(va_arg(args, unsigned int), 1);
	else if (str[i + 1] == 'x')
		ft_putnbr_base_hexa(va_arg(args, int), 0, base);
	else if (str[i + 1] == 'X')
		ft_putnbr_base_hexa(va_arg(args, int), 0, "0123456789ABCDEF");
	else if (str[i + 1] == '%')
		ft_putchar_fd('%', 1);
	else
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_sort_args(str, args, i);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	return (0);
}

int main()
{
	unsigned int x = 6666667;
	int *y = NULL;
	y = malloc(sizeof(int) * 25);

	ft_printf("boula %x\n", x);
	printf("boula %x\n", x);
	ft_printf("boula %X\n", x);
	printf("boula %X\n", x);
	return 0;
}