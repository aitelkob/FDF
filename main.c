/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/08 07:43:41 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "minilibx_macos/mlx.h"

/*double	percent(int	start,int end,int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement /distance));
}
int		get_color(t_drawing  drw,t_mlix *mlix)
{
	t_color color
	int		red;
	int		green;
	int		blue;
	double	percentage;
	color.color_start = 0xff0000;

	if (color.color_start == color.color_end)
		return (color.color_end);
	if (drw.dx > drw.dy)
		percentage = percent(color.color_start,color.color_end,);
}*/

void	draw(t_mlix *mlix)
{
	t_drawing  drw;
	//// point 2 
	mlix->xi = 50;
	mlix->yi = 50;
	int	clore = 0xff0000;
	drw.m = 0;
	drw.dx = mlix->xi - mlix->x;
	drw.dy = mlix->yi - mlix->y;
	drw.m = drw.dy/drw.dx;
	mlx_pixel_put(mlix->ptr,mlix->win,50,50,0x0015ff);
	 mlx_pixel_put(mlix->ptr,mlix->win,40,10,0x0015ff);
	if (drw.dx > 0)
		drw.stepx = 1;
	else
		drw.stepx = -1;
	if (drw.dy > 0)
		drw.stepy = 1;
	else
		drw.stepy = -1;
	if (abs(drw.dx) > abs(drw.dy))
		mlx_pixel_put(mlix->ptr,mlix->win,mlix->x,mlix->y,clore);
	while (mlix->x < mlix->xi && mlix->y < mlix->yi)
	{
		mlix->x= mlix->x + drw.stepx;
		drw.m = drw.m + abs(drw.dy);
		if (drw.m >= abs(drw.dx))
		{
			mlix->y= mlix->y + drw.stepy;
			drw.m = drw.m - drw.dx;
		}
		mlx_pixel_put(mlix->ptr,mlix->win,mlix->x,mlix->y,clore);
	}
	/*x = mlix->x;

	while(x <= mlix->xi)
	{
		mlx_pixel_put(mlix->ptr,mlix->win,mlix->x,mlix->y,clore);
		x = x + 1/drw.m;
	}*/

	//mlx_pixel_put(mlix->ptr,mlix->win,x2,y2,0x00040FF);
}
int key_press(int keycode,t_mlix *mlix)
{

	if (keycode == 124 )
	{
		mlix->x += 10;
		mlix->xi +=10;
	}
	else if (keycode == 123)
		mlix->x -= 10;
	else if (keycode == 125 )
	{
		mlix->y += 10;
		 mlix->yi +=10;
	}
	else if (keycode == 126 )
		mlix->y -= 10;
	else if (keycode == 53)
		exit (0);
	//mlx_clear_window(mlix->ptr,mlix->win);
	draw(mlix);
	return (0);
}

int     main(int ac, char **av)
{
	t_mlix  *mlix;

	if (!(mlix = (t_mlix*)malloc(sizeof(t_mlix))))
		ft_erreur_fd("errrrrrrrrrrrrrrrore");
	(void)ac;
	(void)av;
	//void *param;
	//start(av,mlix);
	//mlxstart();
	mlix->ptr = mlx_init();
	int	x = 2000;	
	int	y = 1980;
	/*int	ix = 100;
	int	iy = 100;*/
	mlix->x = 40;
	mlix->y = 10;
	mlix->win = mlx_new_window(mlix->ptr,x,y,"FDF");
	/*while (s<1000)
	  {
	  mlx_pixel_put(mlix->ptr,mlix->win,s,s*o+60,0xfffFFF);
	  r = 1 / o;
	  s=s+r;
	  }*/
	draw(mlix);
	mlx_hook(mlix->win,2 , 0 , key_press,mlix);
	mlx_loop(mlix->ptr);
	free(mlix);
	return(0);    
}
