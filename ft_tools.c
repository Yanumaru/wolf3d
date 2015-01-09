/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:31:31 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 23:17:58 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "wolf3d.h"
#include <libft.h>
#include <math.h>

int		ft_up(t_make *make)
{
	t_coor	coor;

	coor.x = 1200 / make->tab.col;
	coor.y = 1000 / make->tab.line;
	coor.ang = make->cam.cam_ang * 3.14 / 180.00;
	coor.x2 = make->cam.cam_x + cos(coor.ang) * coor.x / 30.00;
	coor.y2 = make->cam.cam_y - sin(coor.ang) * coor.y / 30.00;
	coor.x = coor.x2 / coor.x;
	coor.y = coor.y2 / coor.y;
	if (coor.x >= 0 && coor.x < make->tab.line && coor.y >= 0
		&& coor.y < make->tab.col
		&& make->tab.tab_ij[(int)coor.y][(int)coor.x] == 0)
	{
		make->cam.cam_x = coor.x2;
		make->cam.cam_y = coor.y2;
	}
	return (1);
}

int		ft_down(t_make *make)
{
	t_coor	coor;

	coor.x = 1200 / make->tab.col;
	coor.y = 1000 / make->tab.line;
	coor.ang = make->cam.cam_ang * 3.14 / 180;
	coor.x2 = make->cam.cam_x - cos(coor.ang) * coor.x / 30.00;
	coor.y2 = make->cam.cam_y + sin(coor.ang) * coor.y / 30.00;
	coor.x = coor.x2 / coor.x;
	coor.y = coor.y2 / coor.y;
	if (coor.x >= 0 && coor.x < make->tab.line && coor.y >= 0
		&& coor.y < make->tab.col
		&& make->tab.tab_ij[(int)coor.y][(int)coor.x] == 0)
	{
		make->cam.cam_x = coor.x2;
		make->cam.cam_y = coor.y2;
	}
	return (1);
}

int		ft_cnt_word(char *str, int c)
{
	int	index_w;
	int	count;

	index_w = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == c)
			index_w = 0;
		else
		{
			if (index_w == 0)
				count++;
			index_w = 1;
		}
		str++;
	}
	return (count);
}

void	ft_put_img(t_img *font, t_make *make)
{
	int	i;

	i = 0;
	while (i < 1000 * make->img.sizeline)
	{
		i++;
		make->img.data[i] = font->data[i];
	}
	font = font;
}

int		ft_put_color(t_make *make, int x, int y, float ang)
{
	float col_x;
	float col_y;
	static int	color;

	col_x = make->x - cos(ang * 3.14 / 180) * 0.1;
	col_y = make->y + sin(ang * 3.14 / 180) * 0.1;
	if (((int)make->x / x != (int)col_x / x)
		&& (int)make->y / y != (int)col_y / y)
		return (color);
	if ((int)make->x / x > (int)col_x / x)
		return (color = 0xDE3163);
	if ((int)make->x / x < (int)col_x / x)
		return (color = 0xB22601);
	if ((int)make->y / y > (int)col_y / y)
		return (color = 0xC60800);
	if ((int)make->y / y < (int)col_y / y)
		return (color = 0xED0000);
	return (color = 0xFFFFFF);
}
