/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:58:34 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/20 10:42:16 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
#include "get_next_line.h"


typedef struct      s_key
{
	double          zoom;
	int             position_x;
	double          altitude;
	int             position_y;
	unsigned    int parallel;
	double			retation_x;
	double          retation_y;
	double			color_h;
	double			color_l;
}                   t_key;

typedef struct		s_drline
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		e2;
	int		sx;
	int		sy;
	int		err;

}					t_drline;

typedef	struct		s_point
{
	int		poinX1;
	int		poinX2;
	int		poinY2;
	int		poinY1;

}					t_point;

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

}					t_drw;
typedef struct		s_color
{
	int		color_pixel;
	int		color_start;
	int     color_currentx;
	int		color_currenty;
	int		color_end;
}					t_color;

typedef  struct     s_mlix
{
	void    *ptr;
	void    *win;
	int		win_x;
	int		win_y;
	int     x ,xi;
	int     y ,yi;
	int     **tab;
	int		center_x;
	int		center_y;
	t_key	key;
	t_color	couleur;
}                   t_mlix;
typedef struct		s_fdf
{
	char    *line;	int     lines;
	int     fd;
	char	**tab;
	int		i;
}					t_fdf;
typedef struct		s_store
{
	char    **tab;
	int     fd;
	char    *line;
	int     n;
	int     i;
}					t_store;
typedef	struct		s_verify
{
	int l;
	int i;
	int **ttab;
	char **splited;
	int count;
	int maxcount;
}					t_verify;

void				drawline(int x0, int y0, int x1, int y1, t_mlix *mlix, int z,int   k);
void				map_drwing(t_mlix *mlix);
void				initt(t_mlix *mlix);
int                 keyhooks(int key, t_mlix *mlix);
int					verify(char **tab,t_mlix *mlix);
char				**store(char **av, int lines);
void				start(char **av,t_mlix *mlix);

#endif
