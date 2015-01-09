/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:08:45 by ykichena          #+#    #+#             */
/*   Updated: 2013/12/02 14:29:27 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s, const char *t, size_t n)
{
	size_t	index;

	index = 0;
	if (!*s && !*t)
		return (0);
	if (!*t)
		return (1);
	while ((*s == *t) && (index < n) && *s)
	{
		s++;
		t++;
		index++;
	}
	if (!*s && *t)
		return (-1);
	return (*(const unsigned char*)s - *(const unsigned char*)t);
}
