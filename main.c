/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:01:39 by yait-el-          #+#    #+#             */
/*   Updated: 2019/10/14 05:35:48 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static  void    init(t_mlibix *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	mlx->bonus.zoom = 0.5;
	mlx->bonus.position_lr = 0;
	mlx->bonus.altitude = 2;
	mlx->bonus.parallel = 0;
	mlx->bonus.position_ud = 0;

}*/
static	void		col_row(t_mlibix *mlx,t_stor	data){
	while (data.stplit[mlx->y] != NULL )
		mlx->y++;
	if (mlx->y <= 1)
	{
		ft_putstr_fd("error\n",2);
		exit(1);
	}
	mlx->tab = (int **)malloc(sizeof(int *) *mlx->y);
	data.i= 0;
	data.stp = ft_strsplit(data.stplit[1],' ');
	while (data.stp[data.i])
	{
		free(data.stp[data.i]);
		(data.i)++;
		mlx->x++;
	}
	free(data.stp);
	data.i = 0;
}

static void		ft_detect_ero(t_stor data)
{
	int i,j;

	i = -1;
	while (data.stplit[++i])
	{
		if (ft_atoi(data.stp[i]) == 0)
		{
			j = -1;
			while (data.stp[i][++j])
				if (!(ft_isdigit(data.stp[i][j])) && data.stp[i][j] != '-')
				{
					ft_putstr_fd("error no numbers \n",2);
					exit(0);
				}
		}
	}
}
static void		store_tab(t_mlibix *mlx,t_stor data)
{
	while (data.i < mlx->y)
	{
		mlx->tab[data.i] = (int *)malloc(sizeof(int)* mlx->x);
		data.stplit = ft_strsplit(data.stplit[data.i],' ');
		free(data.stplit[data.i]);
		data.i = -1;
		ft_detect_ero(data);
		while (data.stp[++(data.j)])
		{
			mlx->tab[data.i][data.j] = ft_atoi(data.stp[data.j]);
			free(data.stp[data.j]);
		}
		free(data.stp);
		(data.i)++;

	}
	free(data.stplit);
}
void	fdf_read(t_mlibix	*mlix,char	**argv)
{
	t_stor      data;
	data.line = ft_strnew(0);
	data.fd = open(argv[1],O_RDONLY);
	printf("daze hena 1");
	while ((data.ret= read(data.fd,data.buff,BUFF_SIZE)))
	{
		if(data.ret < 0)
			exit(1);
		data.buff[data.ret] = '\0';
		data.tmp = ft_strjoin(data.line,data.buff);
		free(data.line);
		data.line = data.tmp;

	}
	data.stplit = ft_strsplit(data.line,'\n');
	col_row(mlix, data);
	store_tab(mlix, data); 
}
int main(int	argc,char	**argv)
{
	t_mlibix	*mlix;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fdf file\n",2);
		return (0);
	}
	else
	{
		mlix =(t_mlibix*)malloc(sizeof(t_mlibix));
		/*initialize the connection between your software and the display 
		 * return a void* identifier
		 * store it in mlx_ptr*/
		(void)argv;
		mlix->mlx_ptr = mlx_init();
		fdf_read(mlix,argv);
		if (mlix->x >= 200)
			    mlix->mlx_win = mlx_new_window(mlix->mlx_ptr, ((200 * 500) / 35),
						            ((200 * 200) / 13), "fdf");
		else
			    mlix->mlx_win = mlx_new_window(mlix->mlx_ptr, ((mlix->x * 500) / 35) * 2,
						            ((mlix->y * 200) / 13) * 2, "fdf");
		/*init(mlix);
		fdf_read(mlix,argv);*/
		/*mlix->x =100;
		if (mlix->x >= 200)
			mlix->mlx_win = mlx_new_window(mlix->mlx_ptr,((200 * 500)/ 35),((200 * 200) / 13),"fdf");
		else
			mlix->mlx_win = mlx_new_window(mlix->mlx_ptr, ((mlix->x * 500) / 35) * 2,
					((mlix->y * 200) / 13) * 2, "fdf");*/
		//mlix->mlx_win = mlx_new_window(mlix->mlx_ptr,1920,1080,"fdf");
		//mlx_loop(mlix->mlx_ptr);
	}
	//mlx_loop(mlix->mlx_ptr);
	return 0;
}
