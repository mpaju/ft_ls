/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:18:59 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/15 16:33:28 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp;
	char	*pattern;

	if (!*str && !*to_find)
		return (str);
	else if (*str && !*to_find)
		return (str);
	while (*str && *to_find)
	{
		tmp = (char *)str;
		pattern = (char *)to_find;
		while (*str == *pattern && *str)
		{
			str++;
			pattern++;
		}
		if (*pattern == '\0')
			return (tmp);
		str = tmp + 1;
	}
	return (0);
}
