/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/22 15:49:25 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resolution(t_mlix *mlix)
{
	mlix->key.position_x = 0;
	mlix->key.position_y = 0;
	mlix->key.parallel = 0;
	mlix->key.retation_x = 0;

	if (mlix->x == 100)
	{
		mlix->win_x = 1980;
		mlix->win_y = 2000;
		mlix->key.zoom = 5;

	}
	else if (mlix->x < 200)
	{
		mlix->win_x = (mlix->x * 70);
		mlix->win_y = (mlix->y * 70);
		mlix->key.zoom = 20;
	}
	else 
	{
		mlix->win_x = 1980;
		mlix->win_y = 1100;
		mlix->key.zoom = 1;
	}
}

void drawmenu(int x0, int y0, int x1, int y1, t_mlix *mlix)
{
	t_color  color;

	t_drline dr;
	dr.dx = abs(x1-x0);
	dr.sx = x0<x1 ? 1 : -1;
	dr.dy = abs(y1-y0);
	dr.sy = y0<y1 ? 1 : -1;
	dr.err = (dr.dx>dr.dy ? dr.dx : -(dr.dy))/2;
	color.color_currentx= x0;
	color.color_currenty = y0;
	while (1)
	{
		mlx_pixel_put(mlix->ptr,mlix->win,x0,y0,0x0048ff);
		if (x0==x1 && y0==y1)
			break;
		dr.e2 = dr.err;
		if (dr.e2 >-(dr.dx))
		{
			dr.err -= dr.dy;
			x0 += dr.sx;

		}
		if (dr.e2 < dr.dy)
		{
			dr.err += dr.dx;
			y0 += dr.sy;

		}
	}
}

void	menu(t_mlix		*mlix)
{
	char	*menu;
	int		win_x = (mlix->win_x - 100);
	drawmenu(0,(mlix->win_y - 300),(mlix->win_x),(mlix->win_y - 300),mlix);
	drawmenu(0,(mlix->win_y - 299),(mlix->win_x),(mlix->win_y - 299),mlix);
	drawmenu(0,(mlix->win_y - 298),(mlix->win_x),(mlix->win_y - 298),mlix);

	menu = "up, down, left, right: movement keys";
	//mlx_string_put(mlix->ptr, mlix->win,win_x / 2, (mlix->win_y - 250), 0xfffFFF, "youssef");
	mlx_string_put(mlix->ptr, mlix->win,(win_x /2) /2, (mlix->win_y - 250), 0xfffFFF, menu);
	menu = "P,I : 3d/2d mode; +, -: zoom";
	mlx_string_put(mlix->ptr, mlix->win,(win_x /2) /2, (mlix->win_y - 50), 0xfffFFF, menu);
	//mlx_string_put(mlix->ptr, mlix->win,win_x / 2, (mlix->win_y - 150), 0xfffFFF, "2youssef");
	menu = "-, +: z-scale; 8,2 : rotation";
	mlx_string_put(mlix->ptr, mlix->win,(win_x /2) /2, (mlix->win_y - 150), 0xfffFFF, menu);
//	mlx_string_put(mlix->ptr, mlix->win,(win_x /2) + ((mlix->win_x /2) /2), (mlix->win_y - 150), 0xffFFF, "3youssef");
	}

int     main(int ac, char **av)
{
	t_mlix  *mlix;
	int		index = -1;
	if (!(mlix = (t_mlix*)malloc(sizeof(t_mlix))))
		ft_erreur_fd("errrrrrrrrrrrrrrrore");
	(void)ac;
	start(&av[1],mlix);
	mlix->ptr = mlx_init();
	//printf(" this is x == %d this is y == %d \n",mlix->x,mlix->y);
	resolution(mlix);
	mlix->win = mlx_new_window(mlix->ptr,mlix->win_x,mlix->win_y,"FDF");
	mlx_hook(mlix->win,2 , 0 , keyhooks,mlix);
	map_drwing(mlix);
	menu(mlix);
	printf("this zoom value %f",mlix->key.zoom);
	mlx_loop(mlix->ptr);
	 while (++index < mlix->y)
		      free(mlix->tab[index]);
	  free(mlix->tab);
	return(0);    
}
