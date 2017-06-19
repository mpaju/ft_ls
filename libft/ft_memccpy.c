/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amt_memccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 01:25:33 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 17:41:42 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	while (n--)
	{
		*tmp = *tmp2;
		if (*tmp == (unsigned char)c)
			return (tmp + 1);
		tmp++;
		tmp2++;
	}
	return (NULL);
}
