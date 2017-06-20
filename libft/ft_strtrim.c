/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:41:26 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 15:10:38 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		c;

	if (!s)
		return (0);
	if ((ret = ft_strdup((char *)s)))
	{
		while (*ret == ' ' || *ret == '\n' || *ret == '\t')
			ret++;
		c = ft_strlen(ret) - 1;
		while (ret[c] == ' ' || ret[c] == '\n' || ret[c] == '\t')
			ret[c--] = 0;
		return (ft_strdup(ret));
	}
	return (0);
}
