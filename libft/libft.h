/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:53:58 by shikim            #+#    #+#             */
/*   Updated: 2023/04/25 07:10:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>

int		ft_nbrlen(int nbr);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);

#endif