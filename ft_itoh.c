/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:06:08 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/18 16:27:22 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_itoh(int nbr, char type);

void	ft_itoh(int nbr, char type)
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
