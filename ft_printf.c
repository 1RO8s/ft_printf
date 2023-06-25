/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:23 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/25 17:03:00 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);

    while(*format != '\0')
    {
        format++;
        if(*(format -1) == '%' && *format == 'd')
            printf("printf decimal\n");
    }
    
    
    // arg1 = va_arg(args,int);


    // printf("args:%d format:%s",arg1,format);
	return (0);
}

// int varargs(...)
// {
//     printf("call varargs\n");
// }

int	main(void)
{
	ft_printf("format text %d\n", 123);
}