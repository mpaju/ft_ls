/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:24:56 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/22 21:02:20 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define NEG(x) (x < 0 ? 1 : 0)
#define ASD(c) (c < 0 ? -c : c)

static int			count_numbers(int n)
{
	int	c;

	c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static unsigned int	convert_num(int n)
{
	unsigned int	u_n;

	if (n == -2147483648)
		u_n = 2147483648;
	else
	{
		n = ASD(n);
		u_n = (unsigned int)n;
	}
	return (u_n);
}

static char			*zero_case(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	ret[0] = '0';
	ret[1] = 0;
	return (ret);
}

char				*ft_itoa(int n)
{
	int				isneg;
	char			*ret;
	int				c;
	unsigned int	u_n;

	if (n == 0)
		return (zero_case());
	isneg = NEG(n);
	u_n = convert_num(n);
	c = count_numbers(n) + isneg;
	if (!(ret = (char *)malloc(sizeof(char) * (c + 1))))
		return (0);
	ret[c] = '\0';
	while (u_n && c--)
	{
		ret[c] = u_n % 10 + '0';
		u_n /= 10;
	}
	if (isneg)
		ret[0] = '-';
	return (ret);
}
