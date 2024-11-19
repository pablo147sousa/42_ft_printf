/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:19:05 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/19 12:38:49 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);

int		ft_atoi(const char *nptr);

char	*ft_strdup(const char *s);

char	*ft_itoa(int n);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

int		ft_putchar(int c);

int		ft_putstr(char *s);

int		ft_printnbr(int n);

int		ft_itoh(unsigned int nbr, char type);

int		ft_printunbr(unsigned int num);

#endif