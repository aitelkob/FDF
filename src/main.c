/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/28 16:42:23 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	mlixinit(t_mlix **mlix)
{
	(*mlix)->ptr = mlx_init();
	(*mlix)->key.position_x = 0;
	(*mlix)->key.position_y = 0;
	(*mlix)->key.parallel = 0;
	(*mlix)->key.retation_x = 0;
	(*mlix)->key.altitude = 1;
	(*mlix)->key.Left_button = 0;
	(*mlix)->latence = 0;
	(*mlix)->stars = 0;
}

void	mlixinitplus(t_mlix **mlix)
{
	(*mlix)->win = mlx_new_window((*mlix)->ptr, (*mlix)->win_x,
	(*mlix)->win_y, "FDF");
	(*mlix)->imgptr = mlx_new_image((*mlix)->ptr, (*mlix)->win_x,
	(*mlix)->win_y);
	(*mlix)->img = mlx_get_data_addr((*mlix)->imgptr, &(*mlix)->bits_per_pixel,
	&(*mlix)->size_line, &(*mlix)->endian);
}

void	resolution(t_mlix *mlix)
{
	mlixinit(&mlix);
	if (mlix->y < 10)
	{
		mlix->win_x = 1000;
		mlix->win_y = 1000;
		mlix->key.zoom = 50;
	}
	else if (mlix->x == 100)
	{
		mlix->win_x = 1980;
		mlix->win_y = 2000;
		mlix->key.zoom = 1000;
	}
	else if (mlix->x < 200)
	{
		mlix->win_x = (mlix->x * 70);
		mlix->win_y = (mlix->y * 70);
		mlix->key.zoom = 20;
	}
	else
	{
		mlix->win_x = 1980;
		mlix->win_y = 1100;
		mlix->key.zoom = 1;
	}
}

void	menu(t_mlix *mlix)
{
	int		centerx;
	int		centery;
	int		i;

	centerx = 0;
	centery = 0;
	i = 0;
	while (++i <= (mlix->win_y) && i <= mlix->win_x)
	{
		imageput(mlix, centerx, centery, 0xfffafa);
		centery = rand() % (mlix->win_y);
		centerx = rand() % (mlix->win_x);
	}
}

int		main(int ac, char **av)
{
	t_mlix	*mlix;
	int		index;

	index = -1;
	if (!(mlix = (t_mlix*)malloc(sizeof(t_mlix))))
		ft_erreur_fd("errrrrrrrrrrrrrrrore");
	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf ", 2);
		exit(0);
	}
	start(&av[1], mlix);
	resolution(mlix);
	mlixinitplus(&mlix);
	mlx_hook(mlix->win, 2, 0, keyhooks, mlix);
	mlx_hook(mlix->win, 4, 0, mouse_press, mlix);
	mlx_hook(mlix->win, 6, 0, mouse_move, mlix);
	map_drwing(mlix);
	mlx_put_image_to_window(mlix->ptr, mlix->win, mlix->imgptr, 0, 0);
	mlx_loop(mlix->ptr);
	while (++index < mlix->y)
		free(mlix->tab[index]);
	free(mlix->tab);
	return (0);
}
