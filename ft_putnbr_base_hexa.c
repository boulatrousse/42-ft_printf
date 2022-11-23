/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:22 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 14:40:25 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_putnbr_base_hexa_bis(long long int nbr, char *base)
{
	int	x;

	x = 0;
	if (nbr >= 0 && nbr < 16)
	{
		ft_putchar_fd(base[nbr], 1);
		x++;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base_hexa_bis((nbr * (-1)), base);
	}
	else if (nbr >= 16)
	{
		ft_putnbr_base_hexa_bis((nbr / 16), base);
		ft_putnbr_base_hexa_bis((nbr % 16), base);
	}
	return (x);
}

int	ft_putnbr_base_hexa(long long int nbr, int check, char *base)
{
	if (check == 1)
		ft_putstr_fd("0x", 1);
	
	return (ft_putnbr_base_hexa_bis(nbr, base));
}
