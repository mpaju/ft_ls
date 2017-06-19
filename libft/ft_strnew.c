/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:37:42 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 15:10:15 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size + 1)
		ret[size--] = 0;
	return (ret);
}
