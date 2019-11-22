/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:02:47 by yait-el-          #+#    #+#             */
/*   Updated: 2019/11/22 11:01:42 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplittt(char const *s, char c,int size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	i = 0;
	k = 0;
	if ((!(s) || !(c)) || (!(tab = (char **)malloc(sizeof(char *) *\
						(size+ 1)))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		if (ft_isword(s, i, c))
		{
			while (s[i + j] != c && s[i + j])
				j++;
			tab[k++] = ft_strsub(s, i, j);
		}
		i++;
	}
	tab[k] = NULL;
	return (tab);
}
