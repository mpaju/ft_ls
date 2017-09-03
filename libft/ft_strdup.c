/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 03:44:52 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 15:07:40 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*mlc;
	char	*tmp;
	int		count;

	tmp = src;
	count = 0;
	while (*(src++) != '\0')
		count++;
	if (!(mlc = (char *)ft_memalloc(count + 1)))
		return (0);
	src = tmp;
	tmp = mlc;
	while (*src != '\0')
	{
		*mlc = *src;
		src++;
		mlc++;
	}
	*mlc = 0;
	return (tmp);
}
