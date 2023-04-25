/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 07:58:07 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 12:19:03 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putunbr(unsigned int unbr)
{
	int				len;
	char			*num;
	unsigned int	copy;
	int				index;

	len = 1;
	copy = unbr;
	index = 0;
	while (copy >= 10)
	{
		++len;
		copy /= 10;
	}
	num = (char *)malloc(len + 1);
	num[len] = '\0';
	while (unbr >= 10)
	{
		num[index++] = unbr % 10 + 48;
		unbr /= 10;
	}
	num[index] = unbr + 48;
	while (index >= 0)
		write(1, &num[index--], 1);
	free(num);
	return (len);
}
