/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_usign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:06:03 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 11:32:58 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_putnbr_fd_usign(unsigned int n, int fd)
{
	if (n == 4294967295)
		write(fd, "4294967295", 10);
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd(n + 48, fd);
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd_usign(n * (-1), fd);
		}
		else
		{
			ft_putnbr_fd_usign((n / 10), fd);
			ft_putnbr_fd_usign((n % 10), fd);
		}
	}
}