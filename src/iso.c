/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:18:06 by babdelka          #+#    #+#             */
/*   Updated: 2019/11/28 03:44:45 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso(int *x, int *y, int z, t_mlix *mlix)
{
	double	previous_x;
	double	previous_y;
	double	l;

	l = 0.523599;
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(l + mlix->key.retation_x);
	*y = -(z) * mlix->key.altitude + (previous_x + previous_y) *
	sin(l + mlix->key.retation_x);
}

void	imageput(t_mlix *mlix, int x, int y, int color)
{
	int i;

	if (x >= 0 && x <= mlix->win_x && y >= 0 && y <= (mlix->win_y))
	{
		i = (x * mlix->bits_per_pixel / 8) + (y * mlix->size_line);
		mlix->img[i] = color;
		mlix->img[++i] = color >> 8;
		mlix->img[++i] = color >> 16;
	}
}
