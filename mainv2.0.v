/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:33 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/03 09:24:04 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

typedef  struct		s_tmp
{
	char	**tab;
	char	**splited;
	int		fd;
	int		n;
	char	*line;
	int		count;
	int		min;
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

void    linescount(char **argv,t_mlix *mlix)
{
	char    *line;
	int     fd;

	fd = open(*argv,O_RDONLY);
	mlix->y = 0;
	while (get_next_line(fd,&line)> 0)
	{
		mlix->y++;
		free(line);

	}
}

void    filltab(t_tmp start,t_mlix *mlix)
{
	int     i;
	int     j;

	printf("de5ale be3da00");
	i = -1;
	if (!(mlix->tab = (int **)malloc(sizeof(int *) * mlix->y)))
		erreur("lay ne3ale zamel bouk ila matalokitiche mlix->tab");

	while (++i < mlix->y)
	{
		j = -1;
		if (!(mlix->tab[i] = (int *)malloc(sizeof(int) * start.count)))
			erreur("9lawi deyaltab 2D matallocatche ");
		while (++j < start.count )
			mlix->tab[i][j] = ft_atoi(start.splited[j]);
	}

}

void	linescou(char	**argv,t_mlix *mlix)
{
	t_tmp start;

	linescount(&argv[1],mlix);
	if (!(start.tab = (char **)malloc(sizeof(char ) * (mlix->y))))
		erreur("tamalek mamabireche te alloca");
	start.n = 0;
	start.min = 0;
	start.fd = open(argv[1],O_RDONLY);
	while (get_next_line(start.fd,&start.line) > 0)
	{
		start.tab[start.n] = ft_strdup(start.line);
		printf("%d._%s \n",start.n,start.tab[start.n]);
		start.splited = ft_strsplit(start.tab[start.n],' ');
		start.count = 0;
		while (start.splited[start.count++]);
		if (start.count > start.min)
			start.min = start.count;
		if (start.count != start.min)
			ft_erreur_fd("mochkile fe error");
		free(start.line);
		start.n++;
	}
	mlix->x = 0;
	while (start.splited[mlix->x])
	{
		mlix->x++;
		 printf("hawa de5ale hena \n");
	}
	 printf("5erje \n");
	//printf("this is y == %d && this is x %d \n ",mlix->y,mlix->x);
	//printf("hawa de5ale hena");
	//filltab(start,mlix);
}
int main(int argc ,char	**argv)
{
	t_mlix	*mlix;

	(void)argc;
	if (!(mlix = (t_mlix *)malloc(sizeof(t_mlix))))
		erreur("start alloc not ok");
	linescou(argv,mlix);
	//free(mlix);
	printf("this is y == %d && this is x %d \n ",mlix->y,mlix->x);
}
