/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 03:46:17 by babdelka          #+#    #+#             */
/*   Updated: 2019/11/28 15:38:38 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		mouse_press(int key, int x, int y, t_mlix *mlix)
{
	x = y;
	if (key == 4)
		mlix->key.zoom += 0.50;
	else if (key == 5 && ((mlix->key.zoom - 0.50) > 0))
		mlix->key.zoom -= 0.50;
	else if (key == 1)
		mlix->key.Left_button = !mlix->key.Left_button;
	ft_memset(mlix->img, mlix->latence, (mlix->win_y * mlix->win_x * 4));
	if (mlix->stars == 1)
		menu(mlix);
	map_drwing(mlix);
	mlx_put_image_to_window(mlix->ptr, mlix->win, mlix->imgptr, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_mlix *mlix)
{
	if (mlix->key.Left_button == 1)
	{
		mlix->key.position_x = x - (mlix->win_x / 2);
		mlix->key.position_y = y - (mlix->win_y / 3);
		ft_memset(mlix->img, mlix->latence, (mlix->win_y * mlix->win_x * 4));
		if (mlix->stars == 1)
			menu(mlix);
		map_drwing(mlix);
		mlx_put_image_to_window(mlix->ptr, mlix->win, mlix->imgptr, 0, 0);
	}
	return (0);
}
