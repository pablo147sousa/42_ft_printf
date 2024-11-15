/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:30:23 by pmoreira          #+#    #+#             */
/*   Updated: 2024/11/15 17:38:06 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		sz;

	sz = ft_strlen(s);
	dup = (char *) malloc((sz * sizeof(char)) + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
