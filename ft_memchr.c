/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:21:08 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/22 22:15:02 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	f;

	tmp = (unsigned char *)str;
	f = (unsigned char)c;
	if (n)
	{
		if (*tmp == f)
			return ((void *)tmp);
		else
			return (ft_memchr((void *)tmp + 1, c, n - 1));
	}
	return (0);
}
