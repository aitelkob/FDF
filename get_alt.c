/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:57:09 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/19 00:57:53 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

static	void		columns_rows(t_mlx *mlx, t_get_alt gtal)
{
	while (gtal.spltn[mlx->y] != NULL)
		mlx->y++;
	if (mlx->y <= 1)
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
	mlx->tab = (int **)malloc(sizeof(int *) * mlx->y);
	gtal.index = 0;
	gtal.splt_spc = ft_strsplit(gtal.spltn[1], ' ');
	while (gtal.splt_spc[gtal.index])
	{
		free(gtal.splt_spc[gtal.index]);
		(gtal.index)++;
		mlx->x++;
	}
	free(gtal.splt_spc);
	gtal.index = 0;
}

static	void		check_error(t_get_alt gtal)
{
	int	i;
	int	j;

	i = -1;
	while (gtal.splt_spc[++i])
	{
		if (ft_atoi(gtal.splt_spc[i]) == 0)
		{
			j = -1;
			while (gtal.splt_spc[i][++j])
				if (!(ft_isdigit(gtal.splt_spc[i][j])) &&
						gtal.splt_spc[i][j] != '-')
				{
					ft_putstr_fd("error no numbers\n", 2);
					exit(1);
				}
		}
	}
}

static	void		fill_table(t_mlx *mlx, t_get_alt gtal)
{
	while (gtal.index < mlx->y)
	{
		mlx->tab[gtal.index] = (int *)malloc(sizeof(int) * mlx->x);
		gtal.splt_spc = ft_strsplit(gtal.spltn[gtal.index], ' ');
		free(gtal.spltn[gtal.index]);
		gtal.jindex = -1;
		check_error(gtal);
		while (gtal.splt_spc[++(gtal.jindex)])
		{
			mlx->tab[gtal.index][gtal.jindex] =
				ft_atoi(gtal.splt_spc[gtal.jindex]);
			free(gtal.splt_spc[gtal.jindex]);
		}
		free(gtal.splt_spc);
		(gtal.index)++;
	}
	free(gtal.spltn);
}

void				get_alt(t_mlx *mlx, char **argv)
{
	t_get_alt	gtal;

	gtal.line = ft_strnew(0);
	gtal.fd = open(argv[1], O_RDONLY);
	while ((gtal.ret = read(gtal.fd, gtal.buffer, BUFF_SIZE)))
	{
		if (gtal.ret < 0)
		{
			perror("");
			exit(1);
		}
		gtal.buffer[gtal.ret] = '\0';
		gtal.tmp = ft_strjoin(gtal.line, gtal.buffer);
		free(gtal.line);
		gtal.line = gtal.tmp;
	}
	gtal.spltn = ft_strsplit(gtal.line, '\n');
	columns_rows(mlx, gtal);
	fill_table(mlx, gtal);
}
