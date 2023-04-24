/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:31:42 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 07:27:39 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_puthex(unsigned long long num)
{
	size_t				len;
	char				*base_hex;
	unsigned long long	copy;

	len = 1;
	base_hex = "0123456789abcdef";
	copy = num;
	if (num >= 16)
		ft_puthex(num / 16);
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
	len += ft_puthex(addr);
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
	d = -123;
	s = "22";
	p = &d;
	printf("[my printf]\n");
	printf("count: %d\n", ft_printf("%c_%d_%s_%p\n", c, d, s, p));
	printf("\n[printf]\n");
	printf("count: %d\n", printf("%c_%d_%s_%p\n", c, d, s, p));
	return (0);
}
