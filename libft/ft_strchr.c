/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:03:26 by ykichena          #+#    #+#             */
/*   Updated: 2013/11/26 22:20:45 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	f;

	i = 0;
	f = (char) c;
	while (s[i] != f)
	{
		if (!*s++)
			return (0);
	}
	return ((char*) s);
}
