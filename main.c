/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/25 17:22:56 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resolution(t_mlix *mlix)
{
	mlix->key.position_x = 0;
	mlix->key.position_y = 0;
	mlix->key.parallel = 0;
	mlix->key.retation_x = 0;
	mlix->key.altitude = 1;

	if (mlix->x == 100 )
	{
		mlix->win_x = 1980;
		mlix->win_y = 2000;
		mlix->key.zoom = 5;

	}
	else if (mlix->x < 200)
	{
		mlix->win_x = (mlix->x * 70);
		mlix->win_y = (mlix->y * 60);
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
	int		i = 0;
	t_drline dr;
	dr.dx = abs(x1-x0);
	dr.sx = x0<x1 ? 1 : -1;
	dr.dy = abs(y1-y0);
	dr.sy = y0<y1 ? 1 : -1;
	dr.err = (dr.dx>dr.dy ? dr.dx : -(dr.dy))/2;
	color.color_currentx= x0;
	color.color_currenty = y0;
	printf("this start i=%d -- \n start point x=%d y=%d \n stapx =%d stapy =%d \n ----err == %d \n deltax=%d deltay=%d",i,x0,y0,dr.sx,dr.sy,dr.err,dr.dx,dr.dy);
	while (1)
	{
		//mlx_pixel_put(mlix->ptr,mlix->win,x0,y0,0xfffFFF);
		imageput(mlix,x0,y0,(0xCC0000 + 0xff * mlix->key.color_h));
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
		//printf("this start i=%d --  point x=%d y=%d  stapx =%d stapy =%d ----err == %d  deltax=%d deltay=%d \n",i++,x0,y0,dr.sx,dr.sy,dr.err,dr.dx,dr.dy);
	}
}

void	menu(t_mlix		*mlix)
{
	//char	*menu;
	int		centerx = 0;
	int		centery = 0;
	int		i = 0;
	int		l = 315;
	 while (++i <= (mlix->win_y-l) && i <= mlix->win_x)
	  {
		  imageput(mlix,centerx,centery,(0xCC0000 + 0xff * mlix->key.color_h));
		  centery = rand()%(mlix->win_y -l);
		  centerx = rand()%(mlix->win_x);
	  }
	drawmenu(0,0,mlix->win_x,mlix->win_y-l,mlix);
	drawmenu(mlix->win_x,0,0,mlix->win_y-l,mlix);
}

int     main(int ac, char **av)
{
	t_mlix  *mlix;
	int		fd;
	//	int		index = -1;
	if (!(mlix = (t_mlix*)malloc(sizeof(t_mlix))))
		ft_erreur_fd("errrrrrrrrrrrrrrrore");
	(void)ac;
	start(&av[1],mlix);
	mlix->ptr = mlx_init();
	printf(" this is x == %d this is y == %d \n",mlix->x,mlix->y);
	//mlix->x=10;
	//mlix->y=10;
	resolution(mlix);
	mlix->win = mlx_new_window(mlix->ptr,mlix->win_x,mlix->win_y,"FDF");
	mlix->imgptr=mlx_new_image(mlix->ptr, mlix->win_x, mlix->win_y);
	mlix->img = mlx_get_data_addr(mlix->imgptr,&mlix->bits_per_pixel, &mlix->size_line, &mlix->endian);
	mlx_hook(mlix->win,2 , 0 , keyhooks,mlix);
	map_drwing(mlix);
	menu(mlix);

	dprintf((fd = open("/dev/ttys001",O_WRONLY))," size of win x==%d y==%d ----size of map x==%d y==%d \n",mlix->win_x,mlix->win_y,mlix->x,mlix->y);

	mlx_put_image_to_window(mlix->ptr,mlix->win,mlix->imgptr,0,0);
	mlx_loop(mlix->ptr);
		/*while (++index < mlix->y)
		  free(mlix->tab[index]);
		  free(mlix->tab);*/
		//free(mlix->img);
		return(0);    
}
