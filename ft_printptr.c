/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:47:26 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:27 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printptr(unsigned long ptr);
static void	ft_printhex(unsigned long nbr, char type);

static void	ft_printhex(unsigned long nbr, char type)
{
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr]);
	else if (nbr >= 16)
	{
		ft_printhex((nbr / 16), type);
		ft_printhex((nbr % 16), type);
	}
}

int	ft_printptr(unsigned long ptr)
{
	int				size;
	unsigned long	temp;

	size = 0;
	temp = ptr;
	while (ptr > 0)
	{
		ptr /= 16;
		size++;
	}
	write(1, "0x", 2);
	size += 2;
	ft_printhex(temp, 'x');
	return (size);
}