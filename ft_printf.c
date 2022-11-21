/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:35 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/21 10:27:56 by lboulatr         ###   ########.fr       */
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

static void    ft_printf_bis(const char *str, args)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            ft_sort_arg(str, args);
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
    else
        ft_printf_bis(str, args);
    return ((int)ft_strlen(str));
}

int main()
{
    ft_printf("boula %% \n\n");
    printf("%%\n");
    return 0;
}