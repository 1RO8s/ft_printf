/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:23 by hnagasak          #+#    #+#             */
/*   Updated: 2023/07/14 08:49:02 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hex_digit(unsigned int num)
{
	int				digit;
	unsigned int	n;

	digit = 1;
	n = num / 16;
	while (n != 0 && digit++)
		n = n / 16;
	return (digit);
}

static int	ft_count_uint_digit(unsigned int num)
{
	int				digit;
	unsigned int	n;

	digit = 1;
	n = num / 10;
	while (n != 0 && digit++)
		n = n / 10;
	return (digit);
}

static int	ft_count_ptr_digit(uintptr_t num)
{
	int			digit;
	uintptr_t	n;

	digit = 1;
	n = num / 16;
	while (n != 0 && digit++)
		n = n / 16;
	return (digit);
}

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

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

void	ft_ui2a(char *str, unsigned int n, int len)
{
	if (0 <= n && n < 10)
		*str = '0' + n;
	else if (10 <= n)
	{
		ft_ui2a(str, n / 10, len - 1);
		*(str + len - 1) = '0' + (n % 10);
	}
}

int	ft_putuint(unsigned int num)
{
	char	*result;
	int		len;

	len = ft_count_uint_digit(num);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	ft_ui2a(result, num, len);
	ft_putstr(result);
	free(result);
	return (len);
}

char	ft_get_hex_base(unsigned int n, int isUpper)
{
	if (0 <= n && n < 9)
		return ('0' + n);
	else if (10 <= n && n < 16 && isUpper)
		return ('A' + (n - 10));
	else if (10 <= n && n < 16 && !isUpper)
		return ('a' + (n - 10));
	else
		return (0);
}

char	*ft_get_hex_str(char *str, unsigned int n, int len, int isUpper)
{
	if (0 <= n && n < 16)
		*str = ft_get_hex_base(n, isUpper);
	else if (16 <= n)
	{
		ft_get_hex_str(str, n / 16, len - 1, isUpper);
		*(str + len - 1) = ft_get_hex_base(n % 16, isUpper);
	}
	return (str);
}

int	ft_puthex(unsigned int num, int isUpper)
{
	char	*str;
	int		len;

	len = ft_count_hex_digit(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	str = ft_get_hex_str(str, num, len, isUpper);
	ft_putstr(str);
	free(str);
	return (len);
}

char	*ft_get_ptr_str(char *str, uintptr_t n, int len)
{
	if (0 <= n && n < 16)
		*str = ft_get_hex_base(n, 0);
	else if (16 <= n)
	{
		ft_get_ptr_str(str, n / 16, len - 1);
		*(str + len - 1) = ft_get_hex_base(n % 16, 0);
	}
	return (str);
}

int	ft_putptr(uintptr_t ptr)
{
	char	*str;
	int		len;

	len = ft_count_ptr_digit(ptr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	str = ft_get_ptr_str(str, ptr, len);
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	return (len + 2);
}

int	ft_print_specifier(char *c, va_list *args)
{
	int	length;

	length = 0;
	if (*c == 'c')
		length = ft_putchar((char)va_arg(*args, int));
	else if (*c == 's')
		length = ft_putstr(va_arg(*args, char *));
	else if (*c == 'p')
		length = ft_putptr(va_arg(*args, uintptr_t));
	else if (*c == 'd' || *c == 'i')
		length = ft_putnbr(va_arg(*args, int));
	else if (*c == 'u')
		length = ft_putuint(va_arg(*args, unsigned int));
	else if (*c == 'X')
		length = ft_puthex(va_arg(*args, unsigned int), 1);
	else if (*c == 'x')
		length = ft_puthex(va_arg(*args, unsigned int), 0);
	else if (*c == '%')
		length = ft_putchar('%');
	else
		length = ft_putchar(*c);
	return (length);
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
			length += ft_print_specifier(++c, &args);
		else
			length += ft_putchar(*c);
		c++;
	}
	return (length);
}
