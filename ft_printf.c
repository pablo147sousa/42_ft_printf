/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:14:38 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/15 17:43:42 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	ft_inputtype(char *s, va_list item);

static int	ft_inputtype(char *s, va_list item)
{
	if (*s == 'c')
		ft_itoa(item);
	if (*s == 's')
		ft_strdup(item);
	if (*s == 'p')
		ft_strdup(item);
	if (*s == 'd')
		ft_itoa(item);
	if (*s == 'i')
		ft_strdup(item);
	if (*s == 'u')
		ft_strdup(item);
	if (*s == 'x')
		ft_strdup(item);
	if (*s == 'X')
		ft_strdup(item);
	if (*s == '%')
		ft_strdup(item);
}


int	ft_printf(const char *input, ...)
{
	
}