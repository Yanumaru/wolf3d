/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 05:50:24 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 17:55:44 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"
#include <libft.h>

int		ft_rotl(t_make *make)
{
	if (make->cam.cam_ang < 360 -3)
		make->cam.cam_ang += 3;
	else
		make->cam.cam_ang = 0;
	return (1);
}

int		ft_rotr(t_make *make)
{
	if (make->cam.cam_ang == 0)
		make->cam.cam_ang = 360;
	make->cam.cam_ang -= 3;
	return (1);
}

int		ft_keycode(int key, t_make *make)
{
	if (key == 65307)
	{
		mlx_clear_window(make->mlx, make->win);
		mlx_destroy_window(make->mlx, make->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 65361)
		make->left = 1;
	if (key == 65362)
		make->up = 1;
	if (key == 65363)
		make->right = 1;
	if (key == 65364)
		make->down = 1;
	return (0);
}

int		ft_keycode2(int key, t_make *make)
{
	if (key == 65361)
		make->left = 0;
	if (key == 65362)
		make->up = 0;
	if (key == 65363)
		make->right = 0;
	if (key == 65364)
		make->down = 0;
	return (0);
}

int		ft_loop_hook(t_make *make)
{
	int	i;

	i = 0;
	if (make->up == 1)
		i = ft_up(make);
	if (make->down == 1)
		i =	ft_down(make);
	if (make->right == 1)
		i = ft_rotr(make);
	if (make->left == 1)
		i = ft_rotl(make);
	if (i == 1)
		ft_walls(make->save, make);
	return (0);
}
