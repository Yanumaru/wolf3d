/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_lets_go.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:47:40 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 12:44:57 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "wolf3d.h"

int		ft_expose(void *param)
{
	t_make	*make;

	make = (t_make *)param;
	mlx_put_image_to_window(make->mlx, make->win, make->img.img_ptr, 0, 0);
	ft_put_text(make);
	return (0);
}

void	ft_draw_font(t_make *make, t_img *font)
{
	int	i;
	int	get;

	i = 0;
	get = mlx_get_color_value(make->mlx, 0x003366);
	while (i <= 1000 / 2 * font->sizeline)
	{
		font->data[i] = (get & 0xFF);
		font->data[i + 1] = (get & 0xFF00) / 256;
		font->data[i + 2] = (get & 0xFF0000) / 65536;
		i = i + 4;
	}
	get = mlx_get_color_value(make->mlx, 0xFFFFFF);
	while (i <= 1000 *font->sizeline)
	{
		font->data[i] = (get & 0xFF);
		font->data[i + 1] = (get & 0xFF00) / 256;
		font->data[i + 2] = (get & 0xFF0000) / 65536;
		i = i + 4;
	}
}

void	ft_put_background(t_img *font, t_make *make)
{
	font->img_ptr = mlx_new_image(make->mlx, 1200, 1000);
	font->data = mlx_get_data_addr(font->img_ptr, &font->bpp, &font->sizeline,
									&font->endian);
	ft_draw_font(make, font);
}

void	ft_lets_go(t_make *make)
{
	t_img	font;

	make->mlx = mlx_init();
	make->win = mlx_new_window(make->mlx, 1200, 1000, "Wolf3d");
	make->img.img_ptr = mlx_new_image(make->mlx, 1200, 1000);
	make->img.data = mlx_get_data_addr(make->img.img_ptr, &make->img.bpp,
										&make->img.sizeline,
										&make->img.endian);
	ft_put_background(&font, make);
	ft_start(make);
	make->save = font;
	ft_walls(make->save, make);
	mlx_expose_hook(make->win, ft_expose, make);
	mlx_hook(make->win, 2, 1, &ft_keycode, make);
	mlx_hook(make->win, 3, 2, &ft_keycode2, make);
	mlx_loop_hook(make->mlx, &ft_loop_hook, make);
	mlx_loop(make->mlx);
}
