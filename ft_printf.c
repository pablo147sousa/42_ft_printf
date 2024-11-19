/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:14:38 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/19 11:02:15 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_inputtype(const char *s, va_list item);

static int	ft_inputtype(const char *s, va_list item)
{
	if (*s == 'c')
		return (ft_putchar(va_arg (item, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(item, char *)));
	if (*s == 'd')
		return (ft_putnbr(va_arg(item, int)));
	if (*s == 'x')
		return (ft_itoh(va_arg(item, unsigned long), 'x'));
	if (*s == 'X')
		return (ft_itoh(va_arg(item, unsigned long), 'X'));
	if (*s == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	va_start (args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			count += ft_inputtype(input, args);
		}
		else
		{
			write(1, input, 1);
			input++;
			count++;
		}
	}
	return (count);
}

int	main(void)
{
	char	*str;
	int		result;

	str = "teste de";
	result = printf("Expected:%s\n",str);
	printf("Expected:%d\n", result);
	//ft_printf("Result:%s\n",str);
	return (0);
}
