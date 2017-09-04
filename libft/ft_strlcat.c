/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:35:08 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/04 09:38:54 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!size)
		return (ft_strlen(dest));
	i = 0;
	while (dest[i] && i < size)
		i++;
	len = i;
	tmp = (char *)src;
	while (*src && i < size - 1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	if (len < size)
		dest[i] = '\0';
	return (len + ft_strlen(tmp));
}
