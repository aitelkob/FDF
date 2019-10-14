/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:58:34 by yait-el-          #+#    #+#             */
/*   Updated: 2019/10/14 04:57:23 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# define BUFF_SIZE 32000
typedef struct      s_bonus
{
	double          zoom;
	int             position_lr;
	double          altitude;
	int             position_ud;
	unsigned    int parallel : 1;

}                   t_bonus;
typedef struct		s_mlibix
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		**tab;
	 t_bonus bonus;
}                 	t_mlibix;

typedef struct		s_stor
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;
	char	*line;
	char	*tmp;
	char	**stplit;
	char	**stp;
	int		i;
	int		j;

}					t_stor;

#endif
