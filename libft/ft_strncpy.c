/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 01:03:00 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/16 20:13:59 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	char	*tmp;

	tmp = dest;
	while (num-- && *src)
		*dest++ = *src++;
	num++;
	while (num--)
		*dest++ = 0;
	return (tmp);
}
