/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:14:38 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/18 10:52:02 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	ft_inputtype(char *s, va_list item);

static int	ft_inputtype(char *s, va_list item)
{
	if (*s == 'c')
		ft_itoa(va_arg (item, char));
	if (*s == 's')
		ft_strdup(va_arg(item, char *));
	if (*s == 'p')
		ft_strdup(item);
	if (*s == 'd')
		ft_putstr(ft_itoa(va_arg(item, int)));
	if (*s == 'i')
		ft_strdup(item);
	if (*s == 'u')
		ft_strdup(item);
	if (*s == 'x')
		ft_strdup(item);
	if (*s == 'X')
		ft_strdup(item);
	if (*s == '%')
		write(1, "%", 1);
}


int	ft_printf(const char *input, ...)
{
	va_list	args;

	va_start (args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			ft_inputtype(input, args);
		}
	}
	
}