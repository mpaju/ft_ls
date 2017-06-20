/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:42:05 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 16:08:22 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char x)
{
	int	i;
	int	wc;
	int	found;

	i = 0;
	wc = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == x)
			found = 0;
		else
		{
			if (found == 0)
				wc++;
			found = 1;
		}
		i++;
	}
	return (wc);
}

static void	count_letters_and_all_mem(char const *s, char x, char **ret)
{
	int	c;
	int	lc;

	c = 0;
	lc = 1;
	while (*s)
	{
		s++;
		if (*s == x || !*s)
		{
			if ((ret[c] = (char *)malloc(sizeof(char) * (lc + 1))))
			{
				ft_bzero(ret[c], lc + 1);
				c++;
				lc = 0;
				while (*s == x && *s != 0)
					s++;
			}
		}
		lc++;
	}
}

static void	push_words(char const *s, char x, char **ret)
{
	int	wc;
	int	lc;

	wc = 0;
	lc = 0;
	while (*s)
	{
		ret[wc][lc++] = *s++;
		if (*s == x || !*s)
		{
			wc++;
			lc = 0;
			while (*s == x && *s)
				s++;
		}
	}
}

char		**ft_strsplit(char const *s, char x)
{
	int		lc;
	char	**ret;

	if (!s)
		return (0);
	while (*s == x)
		s++;
	lc = count_words(s, x);
	if (!(ret = (char **)malloc(sizeof(char*) * (lc + 1))))
		return (0);
	ret[lc] = 0;
	count_letters_and_all_mem(s, x, ret);
	push_words(s, x, ret);
	return (ret);
}
