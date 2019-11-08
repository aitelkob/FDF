/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/06 10:06:22 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		verify(char **tab,t_mlix *mlix)
{
	t_verify	verif;

	verif.maxcount = 0;
	verif.l = -1;
	mlix->tab = (int **)malloc(sizeof(int *) * mlix->y);
	while (++verif.l < mlix->y)
	{
		verif.i = -1;
		verif.splited = ft_strsplit(tab[verif.l], ' ');
		verif.count = 0;
		while (verif.splited[verif.count])
			verif.count++;
		if (verif.count > verif.maxcount)
			verif.maxcount = verif.count;
		if (verif.maxcount != verif.count)
			return (0);
		mlix->tab[verif.l] = (int *)malloc(sizeof(int) * verif.count);
		while (++verif.i < verif.count)
			mlix->tab[verif.l][verif.i] = ft_atoi(verif.splited[verif.i]);
	}
	mlix->x = verif.count;
	//mlxstart(verif.ttab, verif.maxcount, lines);
	return(0);
}

char    **store(char **av, int lines)
{
	t_store		data;

	data.i = 0;
	data.n = 0;
	if (!(data.tab = (char **)malloc(sizeof(char *) * lines)))
		return (0);
	data.fd = open(*av, O_RDONLY);
	while (get_next_line(data.fd, &data.line) > 0)
	{
		data.tab[data.n] = ft_strdup(data.line);
		free(data.line);
		data.n++;
	}
	close(data.fd);
	return (data.tab);
}

int		start(char **av,t_mlix *mlix)
{
	t_fdf	fdf;

	fdf.i = 0;
	fdf.lines = 0;
	fdf.fd = open(*av,O_RDONLY);
	while (get_next_line(fdf.fd,&fdf.line) == 1)
	{
		mlix->y++;
		free(fdf.line);
	}
	close(fdf.fd);
	fdf.tab = store(av, mlix->y);
	verify(fdf.tab, mlix);
	return(0);
}
