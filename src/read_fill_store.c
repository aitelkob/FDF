/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fill_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/28 03:51:42 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	verifloop(t_verify *verif, t_mlix **mlix, char **tab)
{
	while (++verif->l < (*mlix)->y)
	{
		verif->i = -1;
		verif->splited = ft_strsplit(tab[verif->l], ' ');
		verif->count = 0;
		while (verif->splited[verif->count])
			verif->count++;
		if (verif->maxcount == 0)
		{
			verif->maxcount = 1;
			verif->line_one = verif->count;
		}
		if (verif->line_one > verif->count)
			ft_erreur_fd("Found wrong line length. Exiting.");
		(*mlix)->tab[verif->l] = (int *)malloc(sizeof(int) * verif->line_one);
		while (++verif->i < verif->line_one)
		{
			(*mlix)->tab[verif->l][verif->i] =
			ft_atoi(verif->splited[verif->i]);
			free(verif->splited[verif->i]);
		}
		free(verif->splited);
	}
}

int		verify(char **tab, t_mlix *mlix)
{
	t_verify	verif;
	int			i;

	verif.mincount = 0;
	verif.maxcount = 0;
	verif.line_one = 0;
	verif.l = -1;
	mlix->tab = (int **)malloc(sizeof(int *) * mlix->y);
	verifloop(&verif, &mlix, tab);
	mlix->x = verif.line_one;
	if (verif.line_one == 0)
		ft_erreur_fd("No data found.");
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**store(char **av, int lines)
{
	t_store		data;

	data.n = 0;
	if (!(data.tab = (char **)malloc(sizeof(char *) * (lines + 1))))
		ft_putstr_fd("error alocation \n", 2);
	data.fd = open(*av, O_RDONLY);
	while (get_next_line(data.fd, &data.line) > 0)
	{
		data.tab[data.n] = ft_strdup(data.line);
		free(data.line);
		data.n++;
	}
	data.tab[data.n] = NULL;
	close(data.fd);
	return (data.tab);
}

void	start(char **av, t_mlix *mlix)
{
	t_fdf	fdf;

	fdf.fd = open(*av, O_RDONLY);
	mlix->y = 0;
	if (fdf.fd < 0)
		ft_erreur_fd("No file");
	while (get_next_line(fdf.fd, &fdf.line) == 1)
	{
		mlix->y++;
		free(fdf.line);
	}
	close(fdf.fd);
	fdf.tab = store(av, mlix->y);
	verify(fdf.tab, mlix);
}
