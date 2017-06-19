/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:22:14 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/14 01:45:33 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SEP(x) (x == '\v' || x == '\t' || x == ' ' || x == '\n' || x == '\f')
#define SEP2(x) (x == '\r')
#define NUM(x) (x >= '0' && x <= '9')

int	ft_atoi(const char *str)
{
	int	nb;
	int	neg;

	neg = 0;
	nb = 0;
	while (SEP(*str) || SEP2(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (NUM(*str))
	{
		nb *= 10;
		nb += *str - 48;
		str++;
	}
	if (neg)
		return (-nb);
	return (nb);
}
