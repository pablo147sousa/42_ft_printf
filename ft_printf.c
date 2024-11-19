/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:14:38 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:28 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_inputtype(const char *s, va_list item);

static int	ft_inputtype(const char *s, va_list item)
{
	if (*s == 'c')
		return (ft_putchar(va_arg (item, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(item, char *)));
	if (*s == 'd' || *s == 'i')
		return (ft_printnbr(va_arg(item, int)));
	if (*s == 'x')
		return (ft_itoh(va_arg(item, unsigned int), 'x'));
	if (*s == 'X')
		return (ft_itoh(va_arg(item, unsigned int), 'X'));
	if (*s == '%')
		return (ft_putchar('%'));
	if (*s == 'u')
		return (ft_printunbr(va_arg(item, unsigned int)));
	if (*s == 'p')
		return (ft_printptr(va_arg(item, unsigned long)));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	if (input == 0)
		return (-1);
	va_start (args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			count += ft_inputtype(++input, args);
			input++;
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
/* 
int	main(void)
{
	char	*str;
	char	letter;
	int		result;

	result = printf("Expected:\n");
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:\n");
	printf("Result:%d\n", result);
	printf("----------------\n");

	str = "teste de";
	result = printf("Expected:%s\n",str);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%s\n", str);
	printf("Result:%d\n", result);
	printf("----------------\n");

	letter = 'c';
	result = printf("Expected:%c\n", letter);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%c\n", letter);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%d\n", 2+2);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%d\n", 2+2);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%%\n");
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%%\n");
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%x\n", (unsigned int)555555555555);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%x\n", (unsigned int)555555555555);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%X\n", (unsigned int)555555555555);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%X\n", (unsigned int)555555555555);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%i\n", 200 + 55);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%i\n", 200 + 55);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%u\n", (unsigned int)555555555555);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%u\n", (unsigned int)555555555555);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf("Expected:%p\n", str);
	printf("Expected:%d\n", result);
	result = ft_printf("--Result:%p\n", str);
	printf("Result:%d\n", result);
	printf("----------------\n");

	//-Wno-format
	result = printf(" NULL %s NULL \n", NULL);
	printf("Expected:%d\n", result);
	result = ft_printf(" NULL %s NULL \n", NULL);
	printf("Result:%d\n", result);
	printf("----------------\n");

	result = printf(" %p %p \n", 0, 0);
	printf("Expected:%d\n", result);
	result = ft_printf(" %p %p \n", 0, 0);
	printf("Result:%d\n", result);
	printf("----------------\n");
	return (0);
}
 */