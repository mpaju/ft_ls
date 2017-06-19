/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:40:10 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 17:45:49 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	while (len + 1)
	{
		len--;
		ret[len] = s[start + len];
	}
	return (ret);
}
