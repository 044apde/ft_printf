/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:58:07 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 08:02:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int unbr)
{
	size_t			len;
	unsigned int	copy;

	len = 1;
	copy = unbr;
	if (unbr >= 10)
		ft_putnbr(unbr / 10);
	ft_putchar(unbr % 10 + 48);
	len += ft_nbrlen(copy);
	return (len);
}
