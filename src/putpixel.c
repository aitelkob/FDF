/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 02:56:12 by babdelka          #+#    #+#             */
/*   Updated: 2019/11/28 15:02:45 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	putpixel(t_mlix *mlix, t_drw drw, t_color color)
{
	imageput(mlix,
	(int)((mlix->win_x / 2) + drw.xf - (((mlix->x) * mlix->key.zoom) / 2)),
	(int)((mlix->win_y / 2) + drw.yf - (((mlix->x) * mlix->key.zoom) / 3)),
	color.color_start = (drw.i[0] == 0 && drw.i[1] == 0 ? (0xfffFFF + 0xff *
	mlix->key.color_h) : (0x3500D3 + 0xff * mlix->key.color_h)));
}
