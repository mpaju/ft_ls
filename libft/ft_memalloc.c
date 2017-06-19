/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:28:53 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/22 21:14:01 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*ret;

	if (!(ret = (size_t *)malloc(sizeof(size_t) * size)))
		return (0);
	while (size)
	{
		size--;
		ret[size] = 0;
	}
	return (ret);
}
