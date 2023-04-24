/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:31:42 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 03:31:56 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_writeaddress(void *p)
{
	unsigned long long	temp;
	int					len;

	len = 1;
	temp = (unsigned long long)p;
	while (temp / 16 != 0)
	{
		temp /= 16;
		len++;
	}
	write(1, "0x", 2);
	hex_write
	return (len + 2);
}

int	write_va(char c, va_list *ap)
{
	int		count;
	char	*str;

	count = 0;
	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(*ap, int), 1);
		count++;
	}
	else if (c == 's')
	{
		str = ft_itoa(va_arg(*ap, int));
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	else if ('p')
	{
		count += ft_writeaddress(va_arg(*ap, void *));
	}
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
	printf("count: %d\n", printf("%c_%d_%s_%p\n", c, d, s, p));
	return (0);
}
