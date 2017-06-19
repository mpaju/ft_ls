/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 03:00:06 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 17:38:05 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*tmp;

	tmp = dest;
	if (src <= dest)
	{
		while (num--)
			tmp[num] = ((unsigned char *)src)[num];
	}
	else
		ft_memcpy(dest, src, num);
	return ((void *)dest);
}
