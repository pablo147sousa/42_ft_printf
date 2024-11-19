/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:06:08 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/19 10:23:54 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_itoh(unsigned long nbr, char type);

int	ft_itoh(unsigned long nbr, char type)
{
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	while (nbr >= 16)
	{
		ft_itoh((nbr / 16), type);
		ft_itoh((nbr % 16), type);
	}
	if (nbr < 16)
		ft_putchar(base[nbr]);
}
