/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:58:34 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/08 07:41:07 by yait-el-         ###   ########.fr       */
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
	int             position_lr;
	double          altitude;
	int             position_ud;
	unsigned    int parallel : 1;

}                   t_key;

typedef struct		s_drawing
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		m;
	int		stepx;
	int		stepy;

}					t_drawing;
typedef struct		s_color
{
	int		color_start;
	int		color_current;
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
	t_key	key;
}                   t_mlix;
typedef struct		s_fdf
{
	char    *line;
	int     lines;
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

 int				verify(char **tab,t_mlix *mlix);
 char				**store(char **av, int lines);
 int				start(char **av,t_mlix *mlix);

#endif
