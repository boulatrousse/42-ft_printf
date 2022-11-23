/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:53:52 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/23 15:19:42 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_pnbr_bhexa(long long int nbr, int check, char *base, int *x);
int		ft_putnbr_fd_usign(unsigned int n, int fd);
int		ft_putchar_fd_count(char c, int fd);
int		count(long long int n);
int		ft_putstr_fd_count(char *s, int fd);
int		ft_putnbr_fd_count(int n, int fd);

#endif
