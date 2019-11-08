/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 03:01:39 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/04 13:20:24 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putstr_fd(str,2);
	exit(0);
}

static	void		col_row(t_mlibix *mlx,t_stor	data)
{
	mlx->x =0;
	mlx->y = 0;
	printf("de5ale col_row \n");
	while (data.stplit[mlx->y] != NULL )
		mlx->y++;
	if (mlx->y <= 1)
	{
		ft_putstr_fd("error\n",2);
		exit(1);
	
	if (!(mlx->tab = (int **)malloc(sizeof(int *) *mlx->y)))
		error("mlx->tab alloc faille");
	else
		printf("alloc ok2 \n");
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
	printf("this is x == %d \n this is y == %d \n",mlx->x,mlx->y);
	printf(" 5erje men col_rom\n");
}

static void		ft_detect_ero(t_stor data)
{
	int i;
	int	j;

	i = -1;
	while (data.stplit[++i])
	{
		if (ft_atoi(data.stplit[i]) == 0)
		{
			j = -1;
			while (data.stplit[i][++j])
				if (!(ft_isdigit(data.stplit[i][j])) &&
						data.stplit[i][j] != '-')
				{
					ft_putstr_fd("error no numbers \n",2);
					exit(1);
				}
		}
	}
	printf("5erjti hena aweld 9a7ba hena  \n");
}
static void		store_tab(t_mlibix *mlx,t_stor data)
{
	printf("de5ale store tab \n");
	while (data.i < mlx->y)
	{
		if (!(mlx->tab[data.i] = (int *)malloc(sizeof(int)* mlx->x)))
			error("mlx->x alloc faill");
		else
			printf("alloc ok3 \n");
		data.stplit = ft_strsplit(data.stplit[data.i],' ');
		free(data.stplit[data.i]);
		data.i = -1;
		ft_detect_ero(data);
		 printf("hena hena 5  \n");
		 printf("stplit= == %d \n",data.j);
		while (data.stplit[++(data.j)])
		{
			 printf("hena hena 6  \n");
			 //printf("stplit= == %d",data.j);
			mlx->tab[data.i][data.j] = ft_atoi(data.stplit[data.j]);
			free(data.stplit[data.j]);
			 printf("hena hena 7  \n");
		}
		free(data.stplit);
		(data.i)++;

	}
	free(data.stplit);
	printf("5erje men li store_tab \n");
}
void	fdf_read(t_mlibix	*mlix,char	**argv)
{
	int 	i = 0;
	t_stor      data;
	data.line = ft_strnew(0);
	data.fd = open(argv[1],O_RDONLY);
	printf("daze hena 1 \n");
	while ((data.ret= read(data.fd,data.buff,BUFF_SIZE)))
	{
		printf("daze hena 2 \n");
		printf("che7ale men mera boucla %d \n",i);
		if(data.ret < 0)
		{
			error("ma9ra ta 9alwa");
			exit(1);
		}
		printf("hebese hena \n");
		data.buff[data.ret] = '\0';
		data.tmp = ft_strjoin(data.line,data.buff);
		free(data.line);
		data.line = data.tmp;

	}
	printf("daze hena 3 \n");
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
		if (!(mlix =(t_mlibix*)malloc(sizeof(t_mlibix))))
			error("alloc  t_mlibix faille");
		else
			printf("alloc ok1 \n");
		/*initialize the connection between your software and the display 
		 * return a void* identifier
		 * store it in mlx_ptr*/
		//(void)argv;
		//mlix->mlx_ptr = mlx_init();
		fdf_read(mlix,argv);
		 printf("salate function fdf_read \n");
		/*if (mlix->x >= 200)
			    mlix->mlx_win = mlx_new_window(mlix->mlx_ptr, ((200 * 500) / 35),
						            ((200 * 200) / 13), "fdf");
		else
			    mlix->mlx_win = mlx_new_window(mlix->mlx_ptr, ((mlix->x * 500) / 35) * 2,
						            ((mlix->y * 200) / 13) * 2, "fdf");*/
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
