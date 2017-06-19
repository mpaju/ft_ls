/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:35:48 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 15:09:50 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		c2;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	c = 0;
	c2 = 0;
	while (s1[c])
		c++;
	while (s2[c2])
		c2++;
	if (!(ret = (char *)malloc(sizeof(char) * (c + c2) + 1)))
		return (0);
	ret[c + c2] = 0;
	while (c2)
	{
		ret[c + c2 - 1] = s2[c2 - 1];
		c2--;
	}
	c++;
	while (--c)
		ret[c - 1] = s1[c - 1];
	return (ret);
}
