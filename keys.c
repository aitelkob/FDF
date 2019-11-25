/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 03:12:27 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/25 17:35:45 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static  void        keypart(int key, t_mlix *mlix)
{
	int		index;
	index = -1;
	if (key == 53)
	{
		/*while (++index < mlix->y)
			free(mlix->tab[index]);
		free(mlix->tab);*/
		exit(0);
	}
	else if(key == 49)
		mlix->key.color_h +=10;
	else if (key == 124)
		mlix->key.position_x += 20;
	else if (key == 78)
		mlix->key.altitude -= 0.05;
	else if (key == 69)
		mlix->key.altitude += 0.05;
	else if (key == 126)
		mlix->key.position_y -= 20;
	else if (key == 125)
		mlix->key.position_y += 20;
	else if (key == 91)
		mlix->key.retation_x += 0.1;
	else if (key == 84)
		mlix->key.retation_x -= 0.1;
}

int                 keyhooks(int key, t_mlix *mlix)
{
	int	fd;
	keypart(key, mlix);
	if (key == 24)
		mlix->key.zoom += 1;
	else if (key == 27 && (mlix->key.zoom -2) > 0)
		mlix->key.zoom -= 1;
	else if (key == 123)
		mlix->key.position_x -= 20;
	else if (key == 35)
		mlix->key.parallel = 1;
	else if (key == 34)
		mlix->key.parallel = 0;
	ft_memset(mlix->img,0,(mlix->win_y * mlix->win_x *( mlix->bits_per_pixel / 8)));
	map_drwing(mlix);
	menu(mlix);
	mlx_put_image_to_window(mlix->ptr,mlix->win,mlix->imgptr,0,0);
dprintf((fd = open("/dev/ttys000",O_WRONLY))," after modication size of win x==%d y==%d ----size of map x==%d y==%d \n",mlix->win_x,mlix->win_y,mlix->x,mlix->y);
	//menu(mlix);	
	return (0);

}
