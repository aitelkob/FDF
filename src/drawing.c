/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:58:59 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/28 14:36:47 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	structinit(t_drw *drw, t_drline *dr, int x1, int y1)
{
	dr->dx = abs(x1 - drw->xf);
	dr->sx = drw->xf < x1 ? 1 : -1;
	dr->dy = abs(y1 - drw->yf);
	dr->sy = drw->yf < y1 ? 1 : -1;
	dr->err = (dr->dx > dr->dy ? dr->dx : -(dr->dy)) / 2;
}

void	drawline(t_drw drw, int x1, int y1, t_mlix *mlix)
{
	t_color		color;
	t_drline	dr;

	structinit(&drw, &dr, x1, y1);
	color.color_currentx = drw.xf;
	color.color_currenty = drw.yf;
	while (1)
	{
		putpixel(mlix, drw, color);
		if (drw.xf == x1 && drw.yf == y1)
			break ;
		dr.e2 = dr.err;
		if (dr.e2 > -(dr.dx))
		{
			dr.err -= dr.dy;
			drw.xf += dr.sx;
		}
		if (dr.e2 < dr.dy)
		{
			dr.err += dr.dx;
			drw.yf += dr.sy;
		}
	}
}

void	drawone(t_drw drw, t_mlix *mlix)
{
	drw.xf0 = ((drw.x + 1) * (mlix->key.zoom)) + mlix->key.position_x;
	drw.yf0 = ((drw.y) * (mlix->key.zoom)) + mlix->key.position_y;
	if ((mlix->key.parallel))
		iso(&drw.xf0, &drw.yf0, mlix->tab[drw.y][drw.x + 1] *
		mlix->key.zoom, mlix);
	drw.i[0] = mlix->tab[drw.y][drw.x + 1];
	drw.i[1] = mlix->tab[drw.y][drw.x];
	drawline(drw, drw.xf0, drw.yf0, mlix);
}

void	drawtwo(t_drw drw, t_mlix *mlix)
{
	drw.xf2 = (drw.x * mlix->key.zoom) + mlix->key.position_x;
	drw.yf2 = ((1 + drw.y) * mlix->key.zoom) + mlix->key.position_y;
	if ((mlix->key.parallel))
		iso(&drw.xf2, &drw.yf2, mlix->tab[drw.y + 1][drw.x] *
		mlix->key.zoom, mlix);
	drw.i[0] = mlix->tab[1 + drw.y][drw.x];
	drw.i[1] = mlix->tab[drw.y][drw.x];
	drawline(drw, drw.xf2, drw.yf2, mlix);
}

void	map_drwing(t_mlix *mlix)
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
				iso(&drw.xf, &drw.yf, mlix->tab[drw.y][drw.x] * mlix->key.zoom,
				mlix);
			if ((drw.x + 1) < mlix->x)
				drawone(drw, mlix);
			if ((drw.y + 1) < mlix->y)
				drawtwo(drw, mlix);
		}
	}
}
