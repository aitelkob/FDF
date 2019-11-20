/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:58:59 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/20 05:44:20 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static void        iso(int *x, int *y, int z,t_mlix *mlix)
{
	double previous_x;
	double previous_y;
	double	l =  0.523599; 
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(l+mlix->key.retation_x);
	*y = -(z) * mlix->key.altitude + (previous_x + previous_y) * sin(l+ mlix->key.retation_x);
}
//////////////// 33 line remove 8 line and parametre remove 2

void drawline(int x0, int y0, int x1, int y1, t_mlix *mlix, int z,int   k)
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
		mlx_pixel_put(mlix->ptr,mlix->win, (mlix->win_x/2) +x0-
				(((mlix->x) * mlix->key.zoom) /2), (mlix->win_y/3)+y0 -
				(((mlix->x)* mlix->key.zoom) / 3), 
				color.color_start = (z==0 && k == 0 ?
					(0xfffFFF + 0xff *mlix->key.color_h):
					(0xCC0000 + 0xff * mlix->key.color_h)));
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
//// 32 line
void    map_drwing(t_mlix *mlix)
{
	t_drw	drw;

	drw.y = -1;
	while (++(drw.y) < mlix->y)
	{
		drw.x = -1;
		while (++(drw.x) < mlix->x)
		{

			drw.xf = (drw.x * mlix->key.zoom) + mlix->key.position_x;
			drw.yf = (drw.y * mlix->key.zoom) + mlix->key.position_y;
			if ((mlix->key.parallel))
				iso(&drw.xf,&drw.yf,mlix->tab[drw.y][drw.x] * mlix->key.zoom,mlix);
			if ((drw.x + 1) < mlix->x)
			{
				drw.xf0 = ((drw.x + 1) * (mlix->key.zoom)) + mlix->key.position_x;
				drw.yf0 = ((drw.y) * (mlix->key.zoom)) + mlix->key.position_y ;
				if ((mlix->key.parallel))
					iso(&drw.xf0,&drw.yf0,mlix->tab[drw.y][drw.x+1] * mlix->key.zoom,mlix);
				drawline(drw.xf, drw.yf, drw.xf0,drw.yf0, mlix, mlix->tab[drw.y][drw.x + 1],mlix->tab[drw.y][drw.x]);
			}
			if ((drw.y + 1) < mlix->y)
			{
				drw.xf2 = (drw.x  * mlix->key.zoom) + mlix->key.position_x;
				drw.yf2 = ((1+drw.y) * mlix->key.zoom) + mlix->key.position_y;
				if ((mlix->key.parallel))
					iso(&drw.xf2,&drw.yf2,mlix->tab[drw.y+1][drw.x]  * mlix->key.zoom,mlix);
				drawline(drw.xf, drw.yf, drw.xf2, drw.yf2, mlix,mlix->tab[1 + drw.y][drw.x],mlix->tab[drw.y][drw.x]);
			}
		}
	}
}
