/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:11:16 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 19:51:58 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "wolf3d.h"

t_line	*ft_addlist(char *buf)
{
	t_line	*list;

	if (!(list = (t_line *)malloc(sizeof(*list)))
		|| !(list->l = ft_strnew(ft_strlen(buf))))
		return (NULL);
	ft_strcpy(list->l, buf);
	list->next = NULL;
	return (list);
}

int		ft_count(t_line *line)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		line = line->next;
	}
	return (i);
}

int		ft_line(t_line *line)
{
	int	i;
	int	j;

	while (line)
	{
		i = ft_cnt_word(line->l, ' ');
		line = line->next;
		if (line != NULL)
		{
			j = ft_cnt_word(line->l, ' ');
			if (j != i)
			{
				ft_putstr("map not valid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (i);
}

void	ft_get_nbr(t_line *line, int n_line, int n_col, t_make *make)
{
	int		i;
	int		j;
	int		**tab;
	char	**tmp;

	if (!(tab = (int **)malloc(sizeof(*tab) * n_line * n_line)))
		exit(-1);
	i = 0;
	while (i < n_line)
	{
		j = -1;
		if (!(tab[i] = (int *)malloc(sizeof(**tab) * n_col)))
			exit(-1);
		tmp = ft_strsplit(line->l, ' ');
		while (++j < n_col)
			tab[i][j] = ft_atoi(tmp[j]);
		line = line->next;
		i++;
	}
	make->tab.line = n_col;
	make->tab.col = n_line;
	make->tab.tab_ij = tab;
	ft_lets_go(make);
}

void	ft_read(char *file, t_make *make)
{
	int		fd;
	char	*buf;
	t_line	*line;
	t_line	*save_line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	if (get_next_line(fd, &buf))
	{
		line = ft_addlist(buf);
		save_line = line;
	}
	while (get_next_line(fd, &buf))
	{
		line->next = ft_addlist(buf);
		line = line->next;
	}
	ft_get_nbr(save_line, ft_count(save_line), ft_line(save_line), make);
}
