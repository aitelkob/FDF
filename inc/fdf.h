/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:58:34 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/28 15:31:33 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
#include "../inc/get_next_line.h"

typedef struct      s_key
{
	double          zoom;
	int             position_x;
	double          altitude;
	int             position_y;
	unsigned    int parallel;
	double			retation_x;
	double			color_h;
	int				Left_button;
}                   t_key;

typedef struct		s_drline
{
	int		dx;
	int		dy;
	int		e2;
	int		sx;
	int		sy;
	int		err;

}					t_drline;

typedef	struct		s_drw
{
	int				xf;
	int				xf2;
	int				xf0;
	int				yf;
	int				yf2;
	int				yf0;
	int				x;
	int				y;
	int 			i[2];

}					t_drw;

typedef struct		s_color
{
	int		color_start;
	int     color_currentx;
	int		color_currenty;
}					t_color;

typedef  struct     s_mlix
{
	void    *ptr;
	void    *win;
	int		win_x;
	int		win_y;
	int     x;
	int     y;
	int     **tab;
	void	*imgptr;
	char	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		latence;
	int		stars;
	t_key	key;
}                   t_mlix;

typedef struct		s_fdf
{
	char    *line;
	int     fd;
	char	**tab;
}					t_fdf;

typedef struct		s_store
{
	char    **tab;
	int     fd;
	char    *line;
	int     n;
}					t_store;

typedef	struct		s_verify
{
	int l;
	int i;
	char **splited;
	int count;
	int	mincount;
	int	maxcount;
	int	line_one;
}					t_verify;

void				menu(t_mlix     *mlix);
void 				drawline(t_drw	drw, int x1, int y1, t_mlix *mlix);
void				putpixel(t_mlix *mlix, t_drw drw, t_color color);
void				map_drwing(t_mlix *mlix);
void                stor(t_mlix *mlix, char **argv);
void				initt(t_mlix *mlix);
int                 keyhooks(int key, t_mlix *mlix);
int					verify(char **tab,t_mlix *mlix);
char				**store(char **av, int lines);
void				start(char **av,t_mlix *mlix);
void    			iso(int *x, int *y, int z,t_mlix *mlix);
void				imageput(t_mlix *mlix,int x,int y,int color);
int					mouse_press(int key, int x, int y, t_mlix *mlix);
int					mouse_move(int x, int y, t_mlix *mlix);

#endif
