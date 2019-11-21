/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:57:09 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/21 03:39:46 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static	void		col_row(t_mlix *mlix, t_data data)
{
	while (data.splited_n[mlix->y] != NULL)
		mlix->y++;
	if (mlix->y <= 1)
	{
		ft_putstr_fd("error 2\n", 2);
		exit(1);
	}
	mlix->tab = (int **)malloc(sizeof(int *) * mlix->y);
	data.index = 0;
	data.splited_spa = ft_strsplit(data.splited_n[1], ' ');
	while (data.splited_spa[data.index])
	{
		free(data.splited_spa[data.index]);
		(data.index)++;
		mlix->x++;
	}
	free(data.splited_spa);
	data.index = 0;
}

static	void		check_error(t_data data)
{
	int	i;
	int	j;

	i = -1;
	while (data.splited_spa[++i])
	{
		if (ft_atoi(data.splited_spa[i]) == 0)
		{
			j = -1;
			while (data.splited_spa[i][++j])
				if (!(ft_isdigit(data.splited_spa[i][j])) &&
						data.splited_spa[i][j] != '-')
				{
					ft_putstr_fd("error no numbers\n", 2);
					exit(1);
				}
		}
	}
}

static	void		fill_table(t_mlix *mlix, t_data data)
{
	while (data.index < mlix->y)
	{
		mlix->tab[data.index] = (int *)malloc(sizeof(int) * mlix->x);
		data.splited_spa = ft_strsplit(data.splited_n[data.index], ' ');
		free(data.splited_n[data.index]);
		data.jndex = -1;
		check_error(data);
		while (data.splited_spa[++(data.jndex)])
		{
			mlix->tab[data.index][data.jndex] =
				ft_atoi(data.splited_spa[data.jndex]);
			free(data.splited_spa[data.jndex]);
		}
		free(data.splited_spa);
		(data.index)++;
	}
	free(data.splited_n);
}

void				stor(t_mlix *mlix, char **argv)
{
	t_data	data;
	printf("de5ale hena");
	data.line = ft_strnew(0);
	data.fd = open(argv[1], O_RDONLY);
	while ((data.ret = read(data.fd, data.buffer, BUFF_SIZE)))
	{
		if (data.ret < 0)
		{
			printf("errore 1");
			exit(1);
		}
		data.buffer[data.ret] = '\0';
		data.tmp = ft_strjoin(data.line, data.buffer);
		free(data.line);
		data.line = data.tmp;
	}
	data.splited_n = ft_strsplit(data.line, '\n');
	col_row(mlix, data);
	fill_table(mlix, data);
}
