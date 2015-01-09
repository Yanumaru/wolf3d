/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 23:22:42 by ykichena          #+#    #+#             */
/*   Updated: 2013/12/01 23:04:51 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *search, const char *find)
{
	char	*replace_s;
	char	*replace_f;
	char	*index_of_rep;

	if (!*find)
		return ((char *)search);
	replace_s = (char *)search;
	while (*replace_s)
	{
		index_of_rep = replace_s;
		replace_f = (char*)find;
		while (*replace_s && *replace_f && *replace_s == *replace_f)
		{
			replace_s++;
			replace_f++;
		}
		if (!*replace_f)
			return (index_of_rep);
		replace_s = index_of_rep + 1;
	}
	return (NULL);
}
