/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:12:27 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/20 05:57:13 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        initt(t_mlix *mlix)
{
	mlix->key.position_x = 0;
	mlix->key.position_y = 0;
	mlix->key.parallel = 0;
	mlix->key.retation_x = 0;


}

static  void        keypart(int key, t_mlix *mlix)
{

	if (key == 53)
	{
		free(mlix);
		exit(0);
	}
	else if(key == 49)
		mlix->key.color_h +=10;
	else if (key == 124)
		mlix->key.position_x += 10;
	else if (key == 78)
		mlix->key.altitude -= 0.05;
	else if (key == 69)
		mlix->key.altitude += 0.05;
	else if (key == 126)
		mlix->key.position_y -= 5;
	else if (key == 125)
		mlix->key.position_y += 5;
	else if (key == 91)
		mlix->key.retation_x += 0.1;
	else if (key == 84)
		mlix->key.retation_x -= 0.1;
}

int                 keyhooks(int key, t_mlix *mlix)
{
	keypart(key, mlix);
	if (key == 24)
		mlix->key.zoom += 1;
	else if (key == 27 && (mlix->key.zoom -2) > 0)
		mlix->key.zoom -= 1;
	else if (key == 123)
		mlix->key.position_x -= 10;
	else if (key == 35)
		mlix->key.parallel = 1;
	else if (key == 34)
		mlix->key.parallel = 0;
	mlx_clear_window(mlix->ptr, mlix->win);
	map_drwing(mlix);
	return (0);

}
