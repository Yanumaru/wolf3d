/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:56:01 by ykichena          #+#    #+#             */
/*   Updated: 2014/01/19 12:10:11 by ykichena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
** CAMERA POSITON
*/

typedef struct		s_cam
{
	int				cam_x;
	int				cam_y;
	int				cam_ang;
}					t_cam;


typedef struct		s_coor
{
	float			x;
	float			y;
	float			x2;
	float			y2;
	float			ang;
}					t_coor;
/*
** FILE PARSER
*/

typedef struct		s_line
{
	char			*l;
	struct s_line	*next;
}					t_line;

/*
** ARRAY OF X AND Y
*/

typedef struct		s_tab
{
	int				line;
	int				col;
	int				**tab_ij;
}
					t_tab;
/*
** PICTURE PARAMETER
*/

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				x;
	int				y;
}
					t_img;
/*
** ALL
*/

typedef struct		s_make
{
	void			*win;
	void			*mlx;
	t_img			img;
	t_img			save;
	t_img			pat;
	t_cam			cam;
	t_tab			tab;
	float			x;
	float			y;
	int				up;
	int				down;
	int				left;
	int				right;
}					t_make;

/*
** FUNCTIONS
*/

int		ft_put_color(t_make *make, int x, int y, float ang);
int		ft_cnt_word(char *str, int c);
void	ft_read(char *str, t_make *make);
void	ft_lets_go(t_make *make);
void	ft_start(t_make *make);
void	ft_put_img(t_img *font, t_make *make);
void	ft_walls(t_img font, t_make *make);
int		ft_keycode(int key, t_make *make);
int		ft_keycode2(int key, t_make *make);
int		ft_loop_hook(t_make *make);
int		ft_down(t_make *make);
int		ft_up(t_make *make);
void	ft_put_text(t_make *make);

#endif /* !WOLF3D_H */
