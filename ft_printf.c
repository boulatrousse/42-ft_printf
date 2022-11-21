/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:35 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/21 12:56:46 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#include <stdio.h>

static int ft_check_percent(const char *str)
{
    size_t i;
    int symbol;

    i = 0;
    symbol = 0;
    while (str[i])
    {
        if (str[i] == '%')
            symbol++;
        i++;
    }
    if (symbol == 0)
        return (0);
    else
        return (1);
}

static void ft_sort_arg(const char *str, va_list args, size_t i)
{
    if (str[i + 1] == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
    else if (str[i + 1] == 's')
        ft_putstr_fd(va_arg(args, (char *)), 1);
    else if (str[i + 1] == 'p')
        ft_pointer_hex(va_arg(args, (void *)));
    else if (str[i + 1] == 'd')
        ft_putnbr_fd(va_arg(args, int), 1);
    else if (str[i + 1] == 'i')
        
        
}

static void ft_printf_bis(const char *str, args)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            ft_sort_arg(str, args, i);
        i++;
    }
    
}

int ft_printf(const char *str, ...)
{
    va_list args;
    
    va_start(args, str);
    if (ft_check_percent(str) == 0)
    {
        ft_putstr_fd((char *)str, 1);
        return ((int)ft_strlen(str)); 
    }
    ft_printf_bis(str, args);
    return ((int)ft_strlen(str));
}

int main()
{
    ft_printf("boula %% \n\n");
    printf("%%\n");
    return 0;
}