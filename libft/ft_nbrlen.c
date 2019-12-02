/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:10:59 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/19 19:31:55 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		if (n == -2147483648)
			return (10);
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
