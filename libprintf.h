/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:53:52 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 11:34:21 by lboulatr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

void	ft_putnbr_base_hexa(long long int nbr, int check, char *base);
void	ft_putnbr_fd_usign(unsigned int n, int fd);

#endif
