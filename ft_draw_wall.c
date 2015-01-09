/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 01:01:11 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 15:42:54 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include <math.h>
#include <string.h>
#include "wolf3d.h"

void		ft_put_pix_to_img(t_make *make, int color)
{
	int	x;
	int	y;

	if (color == 0xFFFFFF)
		return ;
	x = (int)make->x * make->img.bpp / 8;
	y = (int)make->y * make->img.sizeline;
	make->img.data[x + y] = (color & 0xFF);
	make->img.data[x + y + 1] = (color & 0xFF00) / 256;
	make->img.data[x + y + 2] = (color & 0xFF0000) / 65536;
}

void		ft_draw_wall(t_make *make, double ang, int colr, int index)
{
	float	len;
	float	size;

	len = pow(make->x - make->cam.cam_x, 2);
	len += pow(make->y - make->cam.cam_y, 2);
	len = sqrt(len);
	size = 1000 / len * 25 / cos((make->cam.cam_ang - ang) * 3.14 / 180);
	if (size >= 1000)
		size = 1000;
	make->x = (float)index;
	make->y = (1000 - size) / 2;
	while (make->y <= (1000 + size) / 2)
	{
		ft_put_pix_to_img(make, colr);
		make->y++;
	}
}

void		ft_find(t_make *make, int x, int y, float ang)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = (int)make->x / x;
	y_tmp = (int)make->y / y;
	while (x_tmp >= 0 && x_tmp < make->tab.line
			&& y_tmp >= 0 && y_tmp < make->tab.col
			&& make->tab.tab_ij[y_tmp][x_tmp] == 0)
	{
		make->x += cos(ang * 3.14 / 180) * 2;
		make->y -= sin(ang * 3.14 / 180) * 2;
		x_tmp = (int)make->x / x;
		y_tmp = (int)make->y / y;
	}
	while (x_tmp >= 0 && x_tmp < make->tab.line
			&& y_tmp >= 0 && y_tmp < make->tab.col
			&& make->tab.tab_ij[y_tmp][x_tmp])
	{
		make->x -= cos(ang * 3.14 / 180) * 0.001;
		make->y += sin(ang * 3.14 / 180) * 0.001;
		x_tmp = (int)make->x / x;
		y_tmp = (int)make->y / y;
		if (y_tmp >= make->tab.col)
			return ;
	}
}

void		ft_walls(t_img font, t_make *make)
{
	int		x;
	int		y;
	int		index;
	int		color;
	float	ang;

	index = 0;
	ft_put_img(&font, make);
	x = 1200 / make->tab.col;
	y = 1000 / make->tab.line;
	ang = make->cam.cam_ang + 30 + 360;
	while (ang >= (make->cam.cam_ang - 30 + 360))
	{
		make->x = make->cam.cam_x;
		make->y = make->cam.cam_y;
		ft_find(make, x, y, ang);
		make->x += cos(ang * 3.14 / 180) * 0.1;
		make->y -= sin(ang * 3.14 / 180) * 0.1;
		color = ft_put_color(make, x, y, ang);
		ft_draw_wall(make, ang, color, index);
		ang -= 60.00 / 1200.00;
		index++;
	}
	mlx_put_image_to_window(make->mlx, make->win, make->img.img_ptr, 0, 0);
	ft_put_text(make);
}

void		ft_start(t_make *make)
{
	int		i;
	int		j;

	i = 0;
	while (i < make->tab.line)
	{
		j = 0;
		while (j < make->tab.col)
			if (make->tab.tab_ij[i][j] == 0)
			{
				make->cam.cam_x = (j + 0.25) * (1200 / make->tab.col);
				make->cam.cam_y = (i + 0.25) * (1000 / make->tab.line);
				make->cam.cam_ang = 0;
				return ;
			}
			else
				j++;
		i++;
	}
}
