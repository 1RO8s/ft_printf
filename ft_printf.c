/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:23 by hnagasak          #+#    #+#             */
/*   Updated: 2023/07/06 05:37:43 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	count_hex_digit(int num)
// {
// 	int	digit;
// 	int	n;

// 	digit = 1;
// 	n = num / 16;
// 	while (n != 0 && digit++)
// 		n = n / 16;
// 	return (digit);
// }

// char	*toHex(int num)
// {
// 	char	*hex;

// 	if (0 <= num && num < 10)
// 		*hex = '0' + num;
// 	return (char *)('0' + num);
// }

int	ft_putnbr(int num)
{
	int	len;
	int	tmp;

	len = 1;
	if (num < 0)
		len++;
	tmp = num / 10;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	ft_putnbr_fd(num, 1);
	return (len);
}

int	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*c;
	int		length;

	length = 0;
	c = (char *)format;
	va_start(args, format);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'c')
				length += ft_putchar((char)va_arg(args, int));
			else if (*c == 's')
				length += ft_putstr(va_arg(args, char *));
			else if (*c == 'p')
				printf("printf pointer");
			else if (*c == 'd' || *c == 'i')
				length += ft_putnbr(va_arg(args, int));
			else if (*c == 'u')
				printf("printf unsinged int");
			else if (*c == 'x' || *c == 'X')
				printf("printf lower hexadecimal");
			else if (*c == '%')
				length += ft_putchar('%');
			else
				ft_putchar_fd(*c, 1);
		}
		else
			length += ft_putchar(*c);
		c++;
		// length++;
	}
	return (length);
}
