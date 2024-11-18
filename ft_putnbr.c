/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:22:56 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/18 11:22:57 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

void	ft_putnbr(int n);

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar((n + '0'));
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar(((n % 10) + '0'));
	}
	else
	{
		write(1, "-", 1);
		ft_putnbr((n * (-1)));
	}
}
