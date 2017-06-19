/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:38:13 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 17:44:05 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	char	*ret;

	if (!s)
		return (0);
	c = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (c + 1))))
		return (0);
	ret[c] = 0;
	while (c)
	{
		c--;
		ret[c] = f(s[c]);
	}
	return (ret);
}
