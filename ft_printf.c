/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:31:42 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 04:32:02 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0)
		++length;
	return (length);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	while(*s != '\0')
		write(1, s++, 1);
	return(len);
}

int ft_putnbr(int n)
{
	int	len;

	len  = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			write(1, "-", 1);
			++len;
		}
		while (n / 10 != 0)
		{
			ft_putchar(n % 10 + 48);
			n /= 10;
			++len;
		}
		ft_putchar(n + 48);
		return (len);
	}
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
		count = 0;
	else if (c == 'd')
		count += ft_putnbr(va_arg(*ap, int));
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		count_va;

	count = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			++fmt;
			count_va = write_va(*fmt, &ap);
			if (count_va < 0)
				return (-1);
			count += count_va;
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

int	main(void)
{
	char	c;
	int		d;
	char	*s;
	int		*p;

	c = '0';
	d = 11;
	s = "22";
	p = &d;
	printf("[my printf]\n");
	printf("count: %d\n\n", ft_printf("%c_%d_%s\n", c, d, s));
	printf("[printf]\n");
	printf("count: %d\n", printf("%c_%d_%s\n", c, d, s));
	return (0);
}
