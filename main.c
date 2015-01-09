/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:46:25 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 12:25:01 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "wolf3d.h"

void	ft_put_text(t_make *make)
{
	mlx_string_put(make->mlx, make->win, 10, 30, 0xFFFFFF, "Wolf 3D");
	mlx_string_put(make->mlx, make->win, 10, 50, 0xFFFFFF, "ESC : Quit");
	mlx_string_put(make->mlx, make->win, 10, 70, 0xFFFFFF, "LEFT-RIGHT : Turn");
	mlx_string_put(make->mlx, make->win, 10, 90, 0xFFFFFF, "UP - DOWN: Move");
}

int		main(int argc, char **argv)
{
	t_make	make;

	if (argc == 1)
		ft_putstr("Cannot load map");
	else
		ft_read(argv[1], &make);
	return (0);
}
