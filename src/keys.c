/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:12:27 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/28 15:42:51 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void			checkexit(int key, t_mlix *mlix, int index)
{
	if (key == 53)
	{
		while (++index < mlix->y)
			free(mlix->tab[index]);
		free(mlix->tab);
		exit(0);
	}
}

static void			positionpar(int key, t_mlix *mlix)
{
	if (key == 123)
		mlix->key.position_x -= 20;
	else if (key == 124)
		mlix->key.position_x += 20;
	else if (key == 125)
		mlix->key.position_y += 20;
	else if (key == 126)
		mlix->key.position_y -= 20;
}

static void			positioniso(int key, t_mlix *mlix)
{
	if (key == 123)
	{
		mlix->key.position_x -= 20;
		mlix->key.position_y += 20;
	}
	else if (key == 124)
	{
		mlix->key.position_x += 20;
		mlix->key.position_y -= 20;
	}
	else if (key == 125)
	{
		mlix->key.position_y += 20;
		mlix->key.position_x += 20;
	}
	else if (key == 126)
	{
		mlix->key.position_y -= 20;
		mlix->key.position_x -= 20;
	}
}

static void			keypart(int key, t_mlix *mlix)
{
	int	index;

	index = -1;
	checkexit(key, mlix, index);
	if (mlix->key.parallel == 0)
		positionpar(key, mlix);
	if (mlix->key.parallel == 1)
		positioniso(key, mlix);
	if (key == 49)
		mlix->key.color_h += 10;
	else if (key == 78)
		mlix->key.altitude -= 0.05;
	else if (key == 69)
		mlix->key.altitude += 0.05;
	else if (key == 91)
		mlix->key.retation_x += 0.2;
	else if (key == 84)
		mlix->key.retation_x -= 0.2;
}

int					keyhooks(int key, t_mlix *mlix)
{
	keypart(key, mlix);
	if (key == 24)
		mlix->key.zoom += 0.50;
	else if (key == 27 && ((mlix->key.zoom - 0.50) > 0))
		mlix->key.zoom -= 0.50;
	else if (key == 34)
		mlix->key.parallel = 1;
	else if (key == 35)
		mlix->key.parallel = 0;
	else if (key == 1 && (mlix->stars == 0))
		mlix->stars = 1;
	else if (key == 1 && (mlix->stars == 1))
		mlix->stars = 0;
	else if (key == 13)
		mlix->latence += 20;
	else if (key == 12)
		mlix->latence = 0;
	ft_memset(mlix->img, mlix->latence, (mlix->win_y * mlix->win_x * 4));
	if (mlix->stars == 1)
		menu(mlix);
	map_drwing(mlix);
	mlx_put_image_to_window(mlix->ptr, mlix->win, mlix->imgptr, 0, 0);
	return (0);
}
