/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:45:59 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/13 02:57:48 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char *)ptr1;
	tmp2 = (unsigned char *)ptr2;
	while (num--)
	{
		if (*tmp != *tmp2)
			return (*tmp - *tmp2);
		tmp++;
		tmp2++;
	}
	return (0);
}
