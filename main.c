/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/01 11:22:23 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

typedef  struct		s_tmp
{
	char	**tab;
	char	**splited;
	int		fd;
}					t_tmp;

typedef	 struct		s_mlix
{
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	int		**tab;
}					t_mlix;
void	erreur(char	*str)
{
	ft_putendl_fd(str,2);
	exit(1);
}

void	linescount(char	**argv,t_mlix *mlix)
{
	char	*line;
	int		fd;

	fd = open(*argv,O_RDONLY);
	mlix->y = 0;
	while (get_next_line(fd,&line)> 0)
	{
		mlix->y++;
		free(line);
	}
}
void	verify_filltab(t_tmp start,t_mlix *mlix)
{
	int		i;
	int		j;
	i = -1;
	int	cpt = 0;
	int	max= 0;
	if (!(mlix->tab = (int **)malloc(sizeof(int *) * mlix->y)))
		erreur("lay ne3ale zamel bouk ila matalokitiche mlix->tab");

	while (++i < mlix->y)
	{
		j = -1;
		while (start.splited[cpt])
			cpt++;
		if (cpt > max)
			max = cpt;
		if (max != cpt)
			erreur("file errore");
		if (!(mlix->tab[i] = (int *)malloc(sizeof(int) * cpt)))
			erreur("9lawi deyaltab 2D matallocatche ");
		while (++j < cpt)
			mlix->tab[i][j] = ft_atoi(start.splited[j]);
	}
}
void	store(char	**argv,t_mlix *mlix)
{
	t_tmp	start;
	char	*line;
	int		n;

	//int		i= 0;
	linescount(&argv[1],mlix);
	if (!(start.tab = (char **)malloc(sizeof(char ) * (mlix->y))))
		erreur("tamalek mamabireche te alloca");
	n = 0;
	start.fd = open(argv[1],O_RDONLY);
	while (get_next_line(start.fd,&line) > 0)
	{
		start.tab[n] = ft_strdup(line);
		//printf("%d._%s \n",n,start.tab[n]);
		start.splited = ft_strsplit(start.tab[n],' ');
		free(line);
		n++;
	}
	mlix->x = 0;
	while (start.splited[mlix->x])
		mlix->x++;
	verify_filltab(start,mlix);
	//free(start.splited);
	/*int	i = 0;
	  while (start.tab[i])
	  {
	  free(start.tab[i]);
	  i++;
	  }
	  free(start.tab);*/
}
int main(int argc ,char	**argv)
{
	t_mlix	*mlix;

	(void)argc;
	//int		i = 0;
	//int		n = 0;
	//n = countlines(&argv[1]);
	if (!(mlix = (t_mlix *)malloc(sizeof(t_mlix))))
		erreur("start alloc not ok");
	//linescount(&argv[1],mlix);
	// printf("de5ale hena 1 \n");
	store(argv,mlix);
	free(mlix);
	//printf("this is y == %d && this is x %d \n ",mlix->y,mlix->x);
}
