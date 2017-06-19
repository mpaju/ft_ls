/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 03:58:48 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 18:32:48 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;

	if (!(lil_len = ft_strlen(little)))
		return ((char*)big);
	if (!*big)
		return (NULL);
	if (lil_len > len)
		return (NULL);
	while (*big && len-- - lil_len + 1)
	{
		if (*big == *little && !ft_strncmp(big, little, lil_len))
		{
			return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
