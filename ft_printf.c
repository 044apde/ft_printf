/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:31:42 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 13:34:23 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned int num, char type)
{
	size_t				len;
	char				*base_hex;
	unsigned int		copy;

	len = 1;
	if (type == 'X')
		base_hex = "0123456789ABCDEF";
	else
		base_hex = "0123456789abcdef";
	copy = num;
	if (num >= 16)
		ft_puthex(num / 16, type);
	ft_putchar(base_hex[num % 16]);
	while (copy >= 16)
	{
		++len;
		copy /= 16;
	}
	return (len);
}

static int	ft_putaddrhex(unsigned long long num)
{
	size_t				len;
	char				*base_hex;
	unsigned long long	copy;

	len = 1;
	base_hex = "0123456789abcdef";
	copy = num;
	if (num >= 16)
		ft_putaddrhex(num / 16);
	ft_putchar(base_hex[num % 16]);
	while (copy >= 16)
	{
		++len;
		copy /= 16;
	}
	return (len);
}

static int	ft_putaddr(void *p)
{
	size_t				len;
	unsigned long long	addr;

	len = 2;
	addr = (unsigned long long)p;
	write(1, "0x", 2);
	len += ft_putaddrhex(addr);
	return (len);
}

static int	write_va(char c, va_list *ap)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(*ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (c == 'p')
		count += ft_putaddr(va_arg(*ap, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		count += ft_putunbr(va_arg(*ap, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(*ap, int), c);
	else if (c == 'X')
		count += ft_puthex(va_arg(*ap, int), c);
	else if (c == '%')
	{
		++count;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			++fmt;
			count += write_va(*fmt, &ap);
		}
		else
		{
			write(1, fmt, 1);
			count++;
		}
		++fmt;
	}
	va_end(ap);
	return (count);
}
